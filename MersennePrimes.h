#ifndef MERSENNEPRIMES_H
#define MERSENNEPRIMES_H
#include <gmp.h>
#include <gmpxx.h>
#include <vector>
#include <sstream>
#include <string>
#include <iostream>
#include <map>
#include "Pow2Result.h"
#include "PrimeStatus.h"
#include "PGMersenne.h"
#include "Mytypedefs.h"

/*
This class finds Mersenne primes 2
within a given range of numbers inclusively.
It utilises the multi precision mathematical GMP library.
Written by: Pete Kane
Date: 12-11-2023
Some people have too much time on their hands.
*/
class MersennePrimes
{
public:
	
	MersennePrimes(mpir_ui StartRange, mpir_ui EndRange, bool GiveFeedback);
	void GenerateListOfMersennes();
	std::vector<mpir_ui> GetMPrimes();
	std::vector<Pow2Result> GetResults();
	std::string Summary();
	bool GiveFeedback;
private:
	mpz_t One; // Used for subtraction from pow 2.
	const unsigned int Two = 2; // Used for exponential calculation.
	mpz_t LoopValue;  // The value of LoopIndex.
	mpz_t Pow2Value; // Initial pow2 value. 
	mpz_t Pow2MinusOneValue;// Initial pow2 value -1. 
	mpz_t CurrentPrime; // The current prime
	const unsigned int Probability = 15; // Used by GMP in primality check.
	mpir_ui StartRange; // Generate mersennes starting at this number.
	mpir_ui EndRange; // and ends at this
	mpir_ui LoopIndex;
	std::vector<Pow2Result> Results;
	void AnnounceRunDetails(); // Brief show of runtime parameters
	void GetNextPrime(); // Gets next prime
	bool isPrime = false; // True if normal prime
	bool isMersennePrime = false; // True if mersenne prime
	unsigned int PrimeProbability = 0;// Return value from GMP primality function
	std::size_t RetVal = 0; // Return value from database function
	std::vector<mpir_ui> MPrimes; // The Mersenne primes
	std::string PowerValue; // The P2 -1 value of a possible mersenne.
};
#endif

