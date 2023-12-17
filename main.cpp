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
                std::string Confirm;
		bool SkipPrimalityTest = std::find(Args.begin(), Args.end(), "-skiptest") != Args.end();
		bool ShowProgress = std::find(Args.begin(), Args.end(), "-showprogress") != Args.end();
		std::stringstream ss;
		ss << "Mersenne search will " << (SkipPrimalityTest ? "skip" : "apply") << " the primality test\n";
		ss << "Progress will " << (ShowProgress ? "" : "not ") << "be given\n";
                ss << "Do you want to continue Y/N ? ";
                std::cout << ss.str();

                std::getline(std::cin,Confirm);

                if(Confirm != "Y"  && Confirm != "y")
                   return -1;


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
			MersennePrimes mp(StartRange, EndRange, ShowProgress,SkipPrimalityTest);
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

