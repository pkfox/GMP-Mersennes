#ifndef	MERSENNEPRIME_H
#define MERSENNEPRIME_H
#include <sstream>
#include <string>
#include <pqxx/pqxx>

class MersennePrime
{
public:
	MersennePrime();
	MersennePrime(std::string name);
	MersennePrime(int Prime, std::string Result, int PrimeProbability);
	// Stores the 2 ^ Prime result.
	std::string Result;
	// Stores the prime.
	int Prime;
	// Probability returned by GMP.
	int PrimeProbability;
	std::string PrimeProbabilityText;
	std::string PGTypeName;
};

#endif
