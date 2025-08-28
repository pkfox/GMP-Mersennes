#include "MersennePrimes.h"

std::ostream& operator<<(std::ostream& os, const MersennePrimes& mp) {
    os << (mp.CheckPrimality ? "Executing" : "Skipping") << " primality check";
    return os;
}

MersennePrimes::MersennePrimes() :CheckPrimality(true), StartRange(0), EndRange(0),LoopIndex(0)
{
	mpz_init_set_ui(this->One, 1);
	mpz_init_set_ui(this->Pow2Value, 0);
	mpz_init_set_ui(this->Pow2MinusOneValue, 0);
}

// ctor accepting a start and end range
// and a boolean indicating whether to apply a primality check.
MersennePrimes::MersennePrimes(int StartRange, int EndRange, bool CheckPrimality) :MersennePrimes()
{
	this->StartRange = StartRange;
	this->EndRange = EndRange;
	this->CheckPrimality = CheckPrimality;
}

// Populates a vector of integers containing mersenne primes.
void MersennePrimes::GenerateListOfMersennes()
{
	// Set this->CurrentPrime to this->StartRange
	mpz_init_set_ui(this->CurrentPrime, this->StartRange);
	this->GetNextPrime();
	this->AnnounceRunDetails();
	this->isMersennePrime = false;

	std::stringstream ss;
	ss << "Starting with prime " << this->LoopIndex;
	Utils::PrintMessage(ss.str());

	while(this->LoopIndex <= this->EndRange)
	{
		this->StartOfCalculation = std::chrono::steady_clock::now();
		// Raise 2 ^ this->LoopIndex and put the result in this->Pow2Value
		mpz_ui_pow_ui(this->Pow2Value, this->Two, this->LoopIndex);
		// Subtract 1 from the result and put it in this->Pow2MinusOneValue.
		mpz_sub(this->Pow2MinusOneValue, this->Pow2Value, this->One);
		// and test for primality probability.
		ss.str("");
		ss << *this;
		Utils::PrintMessage(ss.str());
		ss.str("");
		this->PrimeProbability = this->CheckPrimality ? mpz_probab_prime_p(this->Pow2MinusOneValue, this->Probability) : 2;
		this->isMersennePrime = this->PrimeProbability > 0;
		// The possible return values from mpz_probab_prime_p are
		// 0 = Definitely not a prime
		// 1 = Possibly a prime
		// 2 = Definitely a prime

		if (this->isMersennePrime)
		{
			this->MPrimes.push_back(this->LoopIndex);
			this->PowerValue = mpz_get_str(NULL, 10, this->Pow2MinusOneValue);
			ss << this->BuildMersenneMessage();
			Utils::PrintMessage(ss.str());
			ss.clear();
			ss.str("");

			this->EndOfCalculation = std::chrono::steady_clock::now();
			this->CalculateDuration();
			PGMersenne pgm(this->LoopIndex, this->PowerValue, this->PrimeProbability, this->Duration);
			this->RetVal = pgm.EditMersenne();
			ss << "Row id " << this->RetVal << " updated";
			Utils::PrintMessage(ss.str());
		}
		this->GetNextPrime();
	}
}

void MersennePrimes::GetNextPrime()
{
	// Get next prime.
	mpz_nextprime(this->CurrentPrime, this->CurrentPrime);
	// Set this->LoopIndex to the next prime.
	this->LoopIndex = static_cast<unsigned long int>(mpz_get_ui(this->CurrentPrime));
}

// Returns a vector of ints containing the primes.
std::vector<int> MersennePrimes::GetMPrimes()
{
	return this->MPrimes;
}

void MersennePrimes::SetStartRange(unsigned long int StartRange)
{
	this->StartRange = StartRange;
}

void MersennePrimes::SetEndRange(unsigned long int EndRange)
{
	this->EndRange = EndRange;
}

void MersennePrimes::SetPrimalityCheck(bool CheckPrimality)
{
	this->CheckPrimality = CheckPrimality;
}

void MersennePrimes::AnnounceRunDetails()
{
	std::stringstream ss;
	ss << "Searching for Mersenne primes " << "for range " << this->StartRange;
	ss << " -> " << this->EndRange;
	Utils::PrintMessage(ss.str());
}

void MersennePrimes::CalculateDuration()
{
	std::stringstream ss;
	std::chrono::seconds Seconds = std::chrono::duration_cast<std::chrono::seconds>(this->EndOfCalculation - this->StartOfCalculation);
	this->Duration = std::chrono::hh_mm_ss(Seconds);

	std::string DurationString = pqxx::string_traits<std::chrono::hh_mm_ss<std::chrono::seconds>>::to_string(this->Duration);

	ss << "Primality Calculation for " << this->CurrentPrime << " took " << DurationString;

	Utils::PrintMessage(ss.str());
}

std::string MersennePrimes::BuildMersenneMessage() const 
{
    std::ostringstream ss;
    ss << "((" << 2 << "^" << this->LoopIndex << ") - 1) has " << this->PowerValue.length() << " digit"
       << (this->PowerValue.length() > 1 ? "s" : "")
       << " and " << PrimeStatus::GetStatusMessage(PrimeProbability);
    return ss.str();
}