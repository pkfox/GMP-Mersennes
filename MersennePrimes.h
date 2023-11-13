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
	MersennePrimes(int Maximum, bool GiveFeedback);
	void GenerateListOfMersennes();
	std::vector<int> GetMPrimes();
	std::vector<Pow2Result> GetResults();
	std::vector<int> MPrimes;
	std::string Summary();
	bool GiveFeedback;
private:
	mpz_t One; // Used for subtraction from pow 2.
	const unsigned int Two = 2; // Used for exponential calculation.
	mpz_t LoopValue;  // What it says it is.
	mpz_t Pow2; // Initial pow2 value. 
	mpz_t Pow2MinusOne;
	const int Probability = 50; // Used by GMP in primality check.
	int Maximum; // Generate mersennes up to and including this number.
	std::vector<Pow2Result> Results;
};

