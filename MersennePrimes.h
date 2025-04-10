#ifndef MERSENNEPRIMES_H
#define MERSENNEPRIMES_H
#include <gmp.h>
#include <gmpxx.h>
#include <vector>
#include <sstream>
#include <string>
#include <iostream>
#include <map>
#include <chrono>

#include "PrimeStatus.h"
#include "PGMersenne.h"
#include "Utils.h"

/*
This class finds Mersenne primes ((2 ^ P)-1)
where P is a known prime
within a given range of numbers inclusively.
It utilises the multi precision mathematical GMP library.
Written by: Pete Kane
Date: 12-11-2023
Some people have too much time on their hands.
*/

class MersennePrimes
{
public:
	MersennePrimes();
	MersennePrimes(int StartRange, int EndRange, bool CheckPrimality = true);
	void GenerateListOfMersennes();
	[[nodiscard]]
	std::vector<int> GetMPrimes();
	void SetStartRange(unsigned long int StartRange);
	void SetEndRange(unsigned long int EndRange);
	void SetPrimalityCheck(bool CheckPrimality);

private:
	mpz_t One; // Used for subtraction from pow 2.
	const unsigned int Two = 2; // Used for exponential calculation.
	mpz_t Pow2Value; // Initial pow2 value. 
	mpz_t Pow2MinusOneValue;// Initial pow2 value -1. 
	mpz_t CurrentPrime; // The current prime in the loop.
	const unsigned int Probability = 15; // Used by GMP in primality check.
	unsigned long int StartRange; // Generate mersennes starting at this number.
	unsigned long int EndRange; // and end at this.
	unsigned long int LoopIndex;
	void AnnounceRunDetails(); // Concise show of runtime parameters
	void GetNextPrime(); // Gets next prime
	bool isPrime = false; // True if normal prime
	bool isMersennePrime = false; // True if mersenne prime
	unsigned int PrimeProbability = 0;// Return value from GMP primality validation function
	std::size_t RetVal = 0; // Return value from database update function
	std::vector<int> MPrimes; // The Mersenne primes
	std::string PowerValue; // The ((2^P) -1) value of a possible mersenne.
	// Optional primality check
	bool CheckPrimality;

	// Used in elapsed time calculation.
	std::chrono::steady_clock::time_point StartOfCalculation;
	std::chrono::steady_clock::time_point EndOfCalculation;
	std::chrono::hh_mm_ss<std::chrono::seconds> Duration;
	void CalculateDuration();
};
#endif
