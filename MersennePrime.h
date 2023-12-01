#ifndef	MERSENNEPRIME_H
#define MERSENNEPRIME_H
#include <gmpxx.h>
#include <pqxx/pqxx>
#include <sstream>
#include <string>

class MersennePrime
{
public:
	MersennePrime();
	MersennePrime(mpir_ui Prime, std::string Result, int PrimeProbability);
	// Stores the 2 ^ Prime - 1 result.
	std::string Result;
	// Stores the prime.
	mpir_ui Prime;
	// Probability returned by GMP.
	int PrimeProbability;
	std::string PrimeProbabilityText;
};
#endif
