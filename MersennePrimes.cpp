#include "MersennePrimes.h"

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
}

// Generates a vector of ints containing mersennes.
void MersennePrimes::GenerateListOfMersennes()
{
	int i = this->StartRange;
	bool Prime;
	// Get first prime.
	mpz_init_set_ui(this->LoopValue, i);
	mpz_nextprime(this->NextPossiblePrime, this->LoopValue);

	// Trying to save some iterations by jumping to the next prime.
	i = mpz_get_ui(this->NextPossiblePrime);

	while(i <= this->EndRange)
	{
		if(i % 500 == 0 && this->GiveFeedback)
			std::cout << i << "\n";

			// The following statement places the value of i in this->LoopValue.
	
		mpz_init_set_ui(this->LoopValue, i);
		// Get next prime.
		mpz_nextprime(this->NextPossiblePrime, this->LoopValue);

		Prime = mpz_probab_prime_p(this->LoopValue, this->Probability) == 2;
	
		if (Prime)
		{
			// Raise 2 ^ i and put the result in this->Pow2Value
			mpz_ui_pow_ui(this->Pow2Value,this->Two, i);
			// Subtract 1 from the result and put it in this->Pow2MinusOneValue.
			mpz_sub(this->Pow2MinusOneValue,this->Pow2Value,this->One);
		  
			// Get next prime.
			mpz_nextprime(this->NextPossiblePrime, this->LoopValue);
		
			// Trying to save some iterations by jumping to the next prime.
			
			i = mpz_get_ui(this->NextPossiblePrime);

			Prime = mpz_probab_prime_p(this->Pow2MinusOneValue, this->Probability) == 2;
			// and test for primality.
			// The possible return values from mpz_probab_prime_p are
			// 0 = Definitely not a prime
			// 1 = Possibly a prime
			// 2 = Definitely a prime

			if (Prime)
			{
				Pow2Result pr(this->LoopValue,this->Pow2MinusOneValue);
				this->Results.push_back(pr);
				this->MPrimes.push_back(i);
			}
		}
		else
			i++;

		
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
