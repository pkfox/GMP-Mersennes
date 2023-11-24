#ifndef	MERSENNEPRIME_H
#define MERSENNEPRIME_H
//#include "PrimeStatus.h"
#include <sstream>
#include <string>


class MersennePrime
{
public:
	MersennePrime();
	MersennePrime(int Prime, std::string Result, int PrimeProbability);
	// Stores the 2 ^ Prime result.
	std::string Result;
	// Stores the prime.
	int Prime;
	// Probability returned by GMP.
	int PrimeProbability;
	std::string PrimeProbabilityText;
};
#endif
