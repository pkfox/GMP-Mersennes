#ifndef MERSENNEPRIMES_H
#define MERSENNEPRIMES_H
#include <gmp.h>
#include <gmpxx.h>
#include <vector>
#include <sstream>
#include <string>
#include <iostream>
#include <map>
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
namespace pjk
{
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
		mpz_t CurrentPrime; // The current prime
		const unsigned int Probability = 50; // Used by GMP in primality check.
		unsigned long int StartRange; // Generate mersennes starting at this number.
		unsigned long int EndRange; // and ends at this
		unsigned long int LoopIndex;
		void AnnounceRunDetails(); // Brief show of runtime parameters
		void GetNextPrime(); // Gets next prime
		bool isPrime = false; // True if normal prime
		bool isMersennePrime = false; // True if mersenne prime
		unsigned int PrimeProbability = 0;// Return value from GMP primality function
		std::size_t RetVal = 0; // Return value from database function
		std::vector<int> MPrimes; // The Mersenne primes
		std::string PowerValue; // The ((2^P) -1) value of a possible mersenne.
		// Optional primality check
		bool CheckPrimality;
	};
#endif
}

