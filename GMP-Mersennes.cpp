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
	std::vector<Pow2Result> Results;
	std::vector<int> MPrimes;
	MersennePrimes mp;
	mp.GiveFeedback = argc > 2;

	mp.GenerateListOfMersennes(MaxPrimeLimit);
	Results = mp.GetResults();
	MPrimes = mp.GetMPrimes();

	for(auto r:Results)
		PrintMessage(r.Summary());

	std::copy(MPrimes.begin(), MPrimes.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << "\n";
	std::string s;
	std::getline(std::cin, s);
	return 0;
}
