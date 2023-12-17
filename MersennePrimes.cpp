#include "MersennePrimes.h"

// ctor accepting a start and end range
// and a boolean indicating feedback preference.
MersennePrimes::MersennePrimes(mpir_ui StartRange, mpir_ui EndRange, bool SkipPrimalityCheck)
{
	this->StartRange = StartRange;
	this->EndRange = EndRange;
	this->SkipPrimalityCheck = SkipPrimalityCheck;
	mpz_init_set_ui(this->One, 1);
	mpz_init_set_ui(this->Pow2Value, 0);
	mpz_init_set_ui(this->Pow2MinusOneValue, 0);
	mpz_init_set_ui(this->LoopValue, 0);
	mpz_init_set_ui(this->CurrentPrime, this->StartRange);
	this->GetNextPrime();
	this->AnnounceRunDetails();
}

// Populates a vector of integers containing mersenne primes.
void MersennePrimes::GenerateListOfMersennes()
{
	std::stringstream ss;
	ss << "Starting with prime " << this->LoopIndex;
	Utils::PrintMessage(ss.str());

	while (this->LoopIndex <= this->EndRange)
	{
		// Raise 2 ^ this->LoopIndex and put the result in this->Pow2Value
		mpz_ui_pow_ui(this->Pow2Value, this->Two, this->LoopIndex);
		// Subtract 1 from the result and put it in this->Pow2MinusOneValue.
		mpz_sub(this->Pow2MinusOneValue, this->Pow2Value, this->One);
	
		// and test for primality probability.
		this->PrimeProbability = this->SkipPrimalityCheck ? 2: mpz_probab_prime_p(this->Pow2MinusOneValue, this->Probability);
	        
		this->isMersennePrime = this->PrimeProbability > 0;
		// The possible return values from mpz_probab_prime_p are
		// 0 = Definitely not a prime
		// 1 = Possibly a prime
		// 2 = Definitely a prime

		if (this->isMersennePrime)
		{
			std::stringstream ss;
			ss << this->LoopIndex << PrimeStatus::GetStatusMessage(PrimeProbability);
			Utils::PrintMessage(ss.str());
			ss.clear();
			ss.str("");
			// Copy index to this->LoopValue
			mpz_init_set_ui(this->LoopValue, this->LoopIndex);
			Pow2Result pr(this->LoopValue, this->Pow2MinusOneValue, PrimeProbability);
			this->Results.push_back(pr);
			this->MPrimes.push_back(this->LoopIndex);
			this->PowerValue = mpz_get_str(NULL, 10, this->Pow2MinusOneValue);
			PGMersenne pgm(this->LoopIndex, this->PowerValue, this->PrimeProbability);
			this->RetVal = pgm.EditMersenne();
			
			ss << "Row id " << this->RetVal << " updated";
			Utils::PrintMessage(ss.str());
		}
		this->GetNextPrime();
	}
}

// Returns a vector of ints containing the mersennes.
std::vector<mpir_ui> MersennePrimes::GetMPrimes()
{
	return this->MPrimes;
}

// Returns a vector of Pow2Result classes containing a brief computation of the mersennes.
std::vector<Pow2Result> MersennePrimes::GetResults()
{
	return this->Results;
}

// Returns the count of mersennes generated.
std::string MersennePrimes::Summary()
{
	std::stringstream msg;
	msg << this->Results.size() << " Mersenne primes generated ";
	msg << "for the range starting at " << this->StartRange;
	msg << " and ending " << this->EndRange << ".";
	return msg.str();
}

void MersennePrimes::AnnounceRunDetails()
{
	std::stringstream ss;
	ss << "Searching for Mersenne primes ";
	ss << "for range " << this->StartRange;
	ss << " -> " << this->EndRange << ".\n";
	Utils::PrintMessage(ss.str());
}

void MersennePrimes::GetNextPrime()
{
	// Get next prime.
	mpz_nextprime(this->CurrentPrime, this->CurrentPrime);
	// Set this->LoopIndex to the next prime.
	this->LoopIndex = mpz_get_ui(this->CurrentPrime);
}

