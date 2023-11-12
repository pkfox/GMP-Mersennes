#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <iterator>
#include <gmpxx.h>
#include "MersennePrimes.h"


void PrintMessage(std::string msg)
{
	std::cout << msg << "\n";
}

int main(int argc, char** argv)
{
	std::vector<int> MPrimes;
	int MaxPrimeLimit = atoi(argv[1]);
	MersennePrimes mp;
	mp.GenerateListOfMersennes(MaxPrimeLimit);
	MPrimes = mp.GetListOfMPrimes();
	PrintMessage("Mersenne primes");
	std::copy(MPrimes.begin(), MPrimes.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << "\n";
	std::string s;
	std::getline(std::cin, s);
	return 0;
}
