#pragma once
#include <gmpxx.h>
#include <sstream>
class Pow2Result
{
public:
	Pow2Result();
	Pow2Result(mpz_t Prime ,mpz_t Result);
	mpz_t Result;
	mpz_t Prime;
	std::string Summary();
};

