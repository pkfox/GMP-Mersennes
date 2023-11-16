#include "Pow2Result.h"

Pow2Result::Pow2Result()
{
	this->PrimeProbability = 0;
	mpz_init_set_ui(this->Prime, 0);
	mpz_init_set_ui(this->Result,0);
}

Pow2Result::Pow2Result(mpz_t Prime, mpz_t Result, int PrimeProbability) :Pow2Result()
{
	mpz_set(this->Prime,Prime);
	mpz_set(this->Result,Result);
	this->PrimeProbability = PrimeProbability;
	this->ResultLen = mpz_sizeinbase(this->Result, 10);
}



std::string Pow2Result::Summary()
{
	std::stringstream msg;
	msg << "((2 ^ " << this->Prime << ") -1) is " << this->Result << " which " << PrimeStatus::GetStatus(this->PrimeProbability);
	msg << " and has " << ResultLen << " digit" << (this->ResultLen > 1 ? "s":"") << ".";
	return msg.str();
}