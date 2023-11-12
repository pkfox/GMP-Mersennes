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
	int MaxPrimeLimit = atoi(argv[1]);
	std::stringstream msg;
	std::vector<int> MPrimes;
	
	MersennePrimes mp;
	mp.GenerateListOfMersennes(MaxPrimeLimit);
	MPrimes = mp.GetListOfMPrimes();
	msg << MPrimes.size() << " Mersenne primes generated up to the maximum ";
	msg << MaxPrimeLimit << ".";
	PrintMessage(msg.str());

	std::copy(MPrimes.begin(), MPrimes.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << "\n";
	std::string s;
	std::getline(std::cin, s);
	return 0;
}
