#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <iterator>
#include <gmpxx.h>
#include "MersennePrimes.h"
#include <chrono>

void PrintMessage(std::string msg)
{
	std::cout << msg << "\n";
}

int main(int argc, char** argv)
{
	auto beg = std::chrono::high_resolution_clock::now();

	int MaxPrimeLimit = atoi(argv[1]);
	std::vector<Pow2Result> Results;
	MersennePrimes mp(MaxPrimeLimit, argc > 2);
	mp.GenerateListOfMersennes();
	Results = mp.GetResults();
	
	for(Pow2Result Result:Results)
		PrintMessage(Result.Summary());

	auto end = std::chrono::high_resolution_clock::now();

	auto duration = std::chrono::duration_cast<std::chrono::minutes>(end - beg);

	// Displaying the elapsed time
	std::cout << "Elapsed Time: " << duration.count() << " minutes\n";

    std::cout << "Press any key\n";
	std::string s;
	std::getline(std::cin, s);
	return 0;
}
