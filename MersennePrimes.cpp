#include "MersennePrimes.h"


MersennePrimes::MersennePrimes(int Maximum, bool GiveFeedback):Maximum(Maximum),GiveFeedback(GiveFeedback)
{
	mpz_init_set_ui(this->One,1);
	mpz_init_set_ui(this->Pow2,0);
	mpz_init_set_ui(this->Pow2MinusOne, 0);
	mpz_init_set_ui(this->LoopValue, 0);
}


void MersennePrimes::GenerateListOfMersennes()
{
	for (int i = 2; i <= this->Maximum; i++)
	{
		if(i % 500 == 0 && this->GiveFeedback)
			std::cout << i << "\n";

		// The following statement places the value of i in this->LoopValue.
		mpz_init_set_ui(this->LoopValue, i);
		bool Prime = mpz_probab_prime_p(this->LoopValue, this->Probability) == 2;

		if (Prime)
		{
			// Raise 2 ^ i and put the result in this->Pow2
			mpz_ui_pow_ui(this->Pow2,this->Two, i);
			// Subtract 1 from the result and put it in this->Pow2MinusOne.
			mpz_sub(this->Pow2MinusOne,this->Pow2,this->One);

			Prime = mpz_probab_prime_p(this->Pow2, this->Probability) == 2;
			// and test for primality.
			// The possible return values from mpz_probab_prime_p are
			// 0 = Definitely not a prime
			// 1 = Possibly a prime
			// 2 = Definitely a prime

			if (Prime)
			{
				Pow2Result pr(this->LoopValue,this->Pow2MinusOne);
				this->Results.push_back(pr);
				this->MPrimes.push_back(i);
			}
		}
	}
}

std::vector<int> MersennePrimes::GetMPrimes()
{
	return this->MPrimes;
}

std::vector<Pow2Result> MersennePrimes::GetResults()
{
	return this->Results;
}

std::string MersennePrimes::Summary()
{
	std::stringstream msg;
	msg << this->Results.size() << " Mersenne primes generated up to the maximum ";
	msg << this->Maximum << ".";
	return msg.str();
}
