#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <iterator>
#include "MersennePrimes.h"
#include "MersennePrime.h"
#include <chrono>
#include <algorithm>
#include "Utils.h"
#include <algorithm>
#include <regex>

using namespace pqxx;

	int main(int argc, char* argv[])
	{
		std::regex confirm_regex("Y",std::regex_constants::icase);
		std::vector<std::string> Args(argv + 1, argv + argc);
		mpir_ui StartRange;
		mpir_ui EndRange;
		std::vector<Pow2Result> Results;
		std::vector<int> Primes;
		auto beg = std::chrono::high_resolution_clock::now();
		PGMersenne pgm;
        std::string Confirm;
		bool SkipPrimalityTest = std::find(Args.begin(), Args.end(), "-skiptest") != Args.end();
		std::stringstream ss;
		ss << "Mersenne search will " << (SkipPrimalityTest ? "skip" : "apply") << " the primality test\n";
		ss << "Do you want to continue Y/N ? ";
        std::cout << ss.str();
        std::getline(std::cin,Confirm);

		if (! std::regex_search(Confirm, confirm_regex))
			return -1;
				
		pgm.GetData(Primes);

		for (size_t i = 0; i < Primes.size(); i++)
		{
			StartRange = Primes[i] - 1;
			EndRange = Primes[i];
			Results.clear();
			MersennePrimes mp(StartRange, EndRange,SkipPrimalityTest);
			mp.GenerateListOfMersennes();
			Results = mp.GetResults();
			for (Pow2Result Result : Results)
				Utils::PrintMessage(Result.Summary());
		}
	
		auto end = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::minutes>(end - beg);
		std::cout << "Elapsed Time: " << duration.count() << " minutes\n";
		return 0;
	}

