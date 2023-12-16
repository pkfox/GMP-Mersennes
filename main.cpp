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

using namespace pqxx;

	int main(int argc, char* argv[])
	{
		std::vector<std::string> Args(argv + 1, argv + argc);
		
		bool SkipPrimalityTest = std::find(Args.begin(), Args.end(), "-skiptest") != Args.end();
		bool GiveFeedback = std::find(Args.begin(), Args.end(), "-givefeedback") != Args.end();
		std::stringstream ss;
		ss << "Running mersenne search with these parameters\n";
		ss << "Skip primality test = " << (SkipPrimalityTest ? "true" : "false") << "\n";
		ss << "Give feedback = " << (GiveFeedback ? "true" : "false") << "\n";
		Utils::PrintMessage(ss.str());

		std::copy(argv, argv + argc, std::ostream_iterator<char*>(std::cout, "\n"));
		mpir_ui StartRange;
		mpir_ui EndRange;
		std::vector<Pow2Result> Results;

		std::vector<int> Primes;
		auto beg = std::chrono::high_resolution_clock::now();
	
		PGMersenne pgm; 
		pgm.GetData(Primes);

		for (size_t i = 0; i < Primes.size(); i++)
		{
			StartRange = Primes[i] - 1;
			EndRange = Primes[i];
			Results.clear();
			MersennePrimes mp(StartRange, EndRange, GiveFeedback,SkipPrimalityTest);
			mp.GenerateListOfMersennes();
			Results = mp.GetResults();

			if (Results.size() == 0)
				Utils::PrintMessage("No mersennes found");

			for (Pow2Result Result : Results)
				Utils::PrintMessage(Result.Summary());

		}
	
		auto end = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::minutes>(end - beg);

		// Display the elapsed time
		std::cout << "Elapsed Time: " << duration.count() << " minutes\n";

#ifdef _WIN32
		/*Utils::PrintMessage("Press the enter key");
		std::string s;
		std::getline(std::cin, s);*/
#endif
		return 0;
	}

