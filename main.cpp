//#include <iostream>
//#include <sstream>
//#include <string>
//#include <vector>
//#include <iterator>
//#include "MersennePrimes.h"
//#include "MersennePrime.h"
//#include <chrono>
//#include <algorithm>
//#include "Utils.h"
//
//using namespace pqxx;
//
//	int main(int argc, char** argv)
//	{
//		mpir_ui StartRange;
//		mpir_ui EndRange;
//		std::vector<Pow2Result> Results;
//
//		std::vector<int> Primes;
//		auto beg = std::chrono::high_resolution_clock::now();
//	
//		PGMersenne pgm; 
//		pgm.GetData(Primes);
//
//		for (size_t i = 0; i < Primes.size(); i++)
//		{
//			StartRange = Primes[i] - 1;
//			EndRange = Primes[i];
//			Results.clear();
//			MersennePrimes mp(StartRange, EndRange, argc > 3);
//			mp.GenerateListOfMersennes();
//			Results = mp.GetResults();
//
//			if (Results.size() == 0)
//				Utils::PrintMessage("No mersennes found");
//
//			for (Pow2Result Result : Results)
//				Utils::PrintMessage(Result.Summary());
//
//		}
//	
//		auto end = std::chrono::high_resolution_clock::now();
//		auto duration = std::chrono::duration_cast<std::chrono::minutes>(end - beg);
//
//		// Display the elapsed time
//		std::cout << "Elapsed Time: " << duration.count() << " minutes\n";
//
//#ifdef _WIN32
//		/*Utils::PrintMessage("Press the enter key");
//		std::string s;
//		std::getline(std::cin, s);*/
//#endif
//		return 0;
//	}
//
