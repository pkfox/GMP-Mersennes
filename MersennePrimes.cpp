#include "MersennePrimes.h"
#include "PrimeStatus.h"

// ctor accepting a start and end range
// and a boolean indicating feedback preference.
MersennePrimes::MersennePrimes(int StartRange,int EndRange, bool GiveFeedback)
{
	this->StartRange = StartRange;
	this->EndRange = EndRange;
	this->GiveFeedback = GiveFeedback;
	mpz_init_set_ui(this->One,1);
	mpz_init_set_ui(this->Pow2Value,0);
	mpz_init_set_ui(this->Pow2MinusOneValue, 0);
	mpz_init_set_ui(this->LoopValue, 0);
	mpz_init_set_ui(this->NextPossiblePrime, 0);
	this->AnnounceRunDetails();
}

// Populates a vector of integers containing mersenne primes.
void MersennePrimes::GenerateListOfMersennes()
{
	bool Prime;
	bool MersennePrime;
	int PrimeProbability = 0;
	
	for(int i = this->StartRange; i <= this->EndRange;i++)
	{
		// The following statement places the value of i in this->LoopValue.
		mpz_init_set_ui(this->LoopValue, i);
		PrimeProbability = mpz_probab_prime_p(this->LoopValue, this->Probability);
		Prime = PrimeProbability > 0;

		if (Prime)
		{
			// Raise 2 ^ i and put the result in this->Pow2Value
			mpz_ui_pow_ui(this->Pow2Value,this->Two, i);
			// Subtract 1 from the result and put it in this->Pow2MinusOneValue.
			mpz_sub(this->Pow2MinusOneValue,this->Pow2Value,this->One);
			
			PrimeProbability = mpz_probab_prime_p(this->Pow2MinusOneValue, this->Probability);
			MersennePrime = PrimeProbability > 0;

			// and test for primality.
			// The possible return values from mpz_probab_prime_p are
			// 0 = Definitely not a prime
			// 1 = Possibly a prime
			// 2 = Definitely a prime

			if (MersennePrime)
			{
				if (this->GiveFeedback)
					std::cout << i << PrimeStatus::GetStatus(PrimeProbability) << "\n";

				Pow2Result pr(this->LoopValue,this->Pow2MinusOneValue, PrimeProbability);
				this->Results.push_back(pr);
				this->MPrimes.push_back(i);
			}
		}
	}
}

// Returns a vector of ints containing the mersennes.
std::vector<int> MersennePrimes::GetMPrimes()
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
	std::stringstream msg;
	msg << "Searching for Mersenne primes ";
	msg << "for range " << this->StartRange;
	msg << " -> " << this->EndRange << ".\n";
	std::cout << msg.str();
}
