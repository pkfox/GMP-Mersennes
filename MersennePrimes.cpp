#include "MersennePrimes.h"

namespace pjk
{
	MersennePrimes::MersennePrimes()
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
		mpz_init_set_ui(this->CurrentPrime, this->StartRange);
		this->GetNextPrime();
		this->AnnounceRunDetails();

		std::stringstream ss;
		ss << "Starting with prime " << this->LoopIndex;
		Utils::PrintMessage(ss.str());

		while (this->LoopIndex <= this->EndRange)
		{
			this->StartOfCalculation = std::chrono::high_resolution_clock::now();
			// Raise 2 ^ this->LoopIndex and put the result in this->Pow2Value
			mpz_ui_pow_ui(this->Pow2Value, this->Two, this->LoopIndex);
			// Subtract 1 from the result and put it in this->Pow2MinusOneValue.
			mpz_sub(this->Pow2MinusOneValue, this->Pow2Value, this->One);
			// and test for primality probability.
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
				PGMersenne pgm(this->LoopIndex, this->PowerValue, this->PrimeProbability);
				this->RetVal = pgm.EditMersenne();
				std::stringstream ss;
				
				ss << "((2^" << this->LoopIndex << ")-1) is " << this->PowerValue << " has " << this->PowerValue.length() << " digit" << (this->PowerValue.length() > 1 ? "s" : "") << " and" << PrimeStatus::GetStatusMessage(PrimeProbability);
				Utils::PrintMessage(ss.str());
				ss.clear();
				ss.str("");
				ss << "Row id " << this->RetVal << " updated";
				Utils::PrintMessage(ss.str());
			}
			this->EndOfCalculation = std::chrono::high_resolution_clock::now();
			this->PrintCalculationDuration();
			this->GetNextPrime();
		}
	}

	// Returns a vector of ints containing the mersennes.
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

	void MersennePrimes::GetNextPrime()
	{
		// Get next prime.
		mpz_nextprime(this->CurrentPrime, this->CurrentPrime);
		// Set this->LoopIndex to the next prime.
		this->LoopIndex = static_cast<unsigned long int>(mpz_get_ui(this->CurrentPrime));
	}
	void MersennePrimes::PrintCalculationDuration()
	{
		std::chrono::duration_cast<std::chrono::seconds>(this->EndOfCalculation - this->StartOfCalculation);

		std::stringstream ss;
		std::chrono::seconds Seconds = std::chrono::duration_cast<std::chrono::seconds>(this->EndOfCalculation - this->StartOfCalculation);
		std::chrono::seconds Minutes = Seconds / 60;
		std::chrono::seconds Hours = Seconds / (60*60);

		Utils::PrintMessage(ss.str());
	}
}