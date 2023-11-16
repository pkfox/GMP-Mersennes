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
}



std::string Pow2Result::Summary()
{
	size_t ResultLen = mpz_sizeinbase(this->Result,10);
	//PrimeStatus ps;
	std::stringstream msg;
	msg << "((2 ^ " << this->Prime << ") -1) is " << this->Result << " which " << MyPrimeStatus::GetStatus(this->PrimeProbability);
	msg << " and has " << ResultLen << " digit" << (ResultLen > 1 ? "s":"");
	return msg.str();
}