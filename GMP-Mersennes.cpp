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

	int StartRange = atoi(argv[1]);
	int EndRange = atoi(argv[2]);
	std::vector<Pow2Result> Results;
	MersennePrimes mp(StartRange,EndRange, argc > 3);
	mp.GenerateListOfMersennes();
	Results = mp.GetResults();
	
	for(Pow2Result Result:Results)
		PrintMessage(Result.Summary());

	auto end = std::chrono::high_resolution_clock::now();

	auto duration = std::chrono::duration_cast<std::chrono::minutes>(end - beg);

	// Display the elapsed time
	std::cout << "Elapsed Time: " << duration.count() << " minutes\n";

#ifdef _WIN32
    std::cout << "Press any key\n";
    std::string s;
    std::getline(std::cin, s);
#endif
	return 0;
}
