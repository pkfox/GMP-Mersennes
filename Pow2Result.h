#ifndef POW2RESULT_H
#define POW2RESULT_H
#include "PrimeStatus.h"
#include <gmpxx.h>
#include <sstream>
#include <map>
#include <pqxx/pqxx>

class Pow2Result
{
public:
	Pow2Result();
	Pow2Result(mpz_t Prime ,mpz_t Result, int PrimeProbability);
	// Stores the 2 ^ Prime.
	mpz_t Result;
	// Stores the prime.
	mpz_t Prime;
	// Stores the amount of digits in the Result.
	size_t ResultLen;
	// Probability returned by GMP.
	int PrimeProbability;
	// This returns a brief description of the computation.
	std::string Summary();
	pqxx::connection PGConnection;
	//("host=nuc port=5432 dbname=commands user=postgres password=Giraffes09");
	pqxx::zview ConnectionString;
};
#endif
