#include "Pow2Result.h"

Pow2Result::Pow2Result()
{
	mpz_init_set_ui(this->Prime, 0);
	mpz_init_set_ui(this->Result,0);
}

Pow2Result::Pow2Result(mpz_t Prime, mpz_t Result):Pow2Result()
{
	mpz_init_set(this->Prime,Prime);
	mpz_init_set(this->Result,Result);
}

std::string Pow2Result::Summary()
{
	std::stringstream msg;
	msg << "2 raised to the power of " << this->Prime << " -1 is " << this->Result << ".";
	return msg.str();
}
