#include "MersennePrimes.h"

MersennePrimes::MersennePrimes()
{
	this->Maximum = 0;
	mpz_init_set_ui(this->One, 1);
	mpz_init_set_ui(this->Two, 2);
	mpz_init(this->Result);
	mpz_init_set_ui(this->LoopValue, 0);
}


void MersennePrimes::GenerateListOfMersennes(int Maximum)
{
	this->Maximum = Maximum;

	for (int i = 3; i <= this->Maximum; i++)
	{
		mpz_init_set_ui(this->LoopValue, i);
		bool Prime = mpz_probab_prime_p(this->LoopValue, this->Probability) == 2;

		if (Prime)
		{
			// Raise 2 ^ i
			mpz_pow_ui(Result,this->Two, i);
			// Subtract 1 from the result
			mpz_sub(this->Result, this->Result, this->One);
			// and test for primality.
			// The possible return values from mpz_probab_prime_p are
			// 0 = Definitely not a prime
			// 1 = Possibly a prime
			// 2 = Definitely a prime
			Prime = mpz_probab_prime_p(this->Result, this->Probability) == 2;

			if (Prime)
			{
				this->MPrimes.push_back(i);
			}
		}
	}
}

std::vector<int> MersennePrimes::GetListOfMPrimes()
{
	return this->MPrimes;
}
