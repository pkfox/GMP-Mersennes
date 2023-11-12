#include <gmpxx.h>
#include <vector>
#include <sstream>

#pragma once

class MersennePrimes
{
public:
	MersennePrimes();
	void GenerateListOfMersennes(int Maximum);
	std::vector<int> GetListOfMPrimes();
private:
	mpz_t One; // Used for subtraction from pow 2.
	mpz_t Two; // Used for exponential calculation.
	mpz_t LoopValue;  // What it says it is.
	mpz_t Result; // Generic return value container. 
	const int Probability = 30; // Used by GMP in primality check.
	int Maximum;
	std::vector<int> MPrimes;
};

