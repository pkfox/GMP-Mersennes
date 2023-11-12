#include "MersennePrimes.h"


MersennePrimes::MersennePrimes()
{
	this->Maximum = 0;
	mpz_init_set_ui(this->One, 1);
	mpz_init_set_ui(this->Two, 2);
	mpz_init_set_ui(this->Result,0);
	mpz_init_set_ui(this->LoopValue, 0);
}


void MersennePrimes::GenerateListOfMersennes(int Maximum)
{
	this->Maximum = Maximum;

	for (int i = 2; i <= this->Maximum; i++)
	{
		if(i % 500 == 0 && this->GiveFeedback)
			std::cout << i << "\n";

		// This places the value of i in this->LoopValue
		mpz_init_set_ui(this->LoopValue, i);
		bool Prime = mpz_probab_prime_p(this->LoopValue, this->Probability) == 2;

		if (Prime)
		{
			// Raise 2 ^ i and put the result in this->Result
			mpz_pow_ui(this->Result,this->Two, i);
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
				Pow2Result pr(this->LoopValue,this->Result);
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
