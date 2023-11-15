#ifdef _WIN32
#pragma once
#endif
#include "PrimeStatus.h"
#include <gmpxx.h>
#include <sstream>
class Pow2Result
{
public:
	Pow2Result();
	Pow2Result(mpz_t Prime ,mpz_t Result, int PrimeProbability);
	mpz_t Result;
	mpz_t Prime;
	// Probability returned by GMP.
	int PrimeProbability;
	// This returns a brief description of the computation.
	std::string Summary();
};

