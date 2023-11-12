#pragma once
#include <gmpxx.h>
#include <vector>
#include <sstream>
#include <string>
#include <iostream>
#include "Pow2Result.h"

/*
This class generates Mersenne primes up to and including a supplied maximum.
It utilises the GMP library.
Written by: Pete Kane
Date: 12-11-2023
*/
class MersennePrimes
{
public:
	MersennePrimes();
	void GenerateListOfMersennes(int Maximum);
	std::vector<int> GetMPrimes();
	std::vector<Pow2Result> GetResults();
	std::vector<int> MPrimes;
	std::string Summary();
	bool GiveFeedback;
private:
	mpz_t One; // Used for subtraction from pow 2.
	mpz_t Two; // Used for exponential calculation.
	mpz_t LoopValue;  // What it says it is.
	mpz_t Result; // Generic return value container. 
	const int Probability = 30; // Used by GMP in primality check.
	int Maximum;
	std::vector<Pow2Result> Results;
};

