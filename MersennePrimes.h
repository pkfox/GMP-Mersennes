#pragma once
#include <gmpxx.h>
#include <vector>
#include <sstream>
#include <string>
#include <iostream>
#include "Pow2Result.h"

/*
This class finds Mersenne primes 
within a given range of numbers inclusively.
It utilises the multi precision mathematical GMP library.
Written by: Pete Kane
Date: 12-11-2023
Some people have too much time on their hands.
*/
class MersennePrimes
{
public:
	MersennePrimes(int StartRange, int EndRange, bool GiveFeedback);
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
	mpz_t Pow2Value; // Initial pow2 value. 
	mpz_t Pow2MinusOneValue;// Initial pow2 value -1. 
	mpz_t NextPossiblePrime;
	const int Probability = 50; // Used by GMP in primality check.
	int StartRange; // Generate mersennes starting at this number.
	int EndRange; // and ends at this
	std::vector<Pow2Result> Results;
};

