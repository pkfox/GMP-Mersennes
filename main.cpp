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

using namespace pqxx;

static void GetData();
static std::vector<int> Primes;

	int main(int argc, char** argv)
	{
		auto beg = std::chrono::high_resolution_clock::now();
		GetData();
		for (size_t i = 0; i < Primes.size(); i++)
		{
			mpir_ui StartRange = Primes[i] - 1;
			mpir_ui EndRange = Primes[i];
			std::vector<Pow2Result> Results;
			MersennePrimes mp(StartRange, EndRange, argc > 3);
			mp.GenerateListOfMersennes();
			Results = mp.GetResults();

			if (Results.size() == 0)
				Utils::PrintMessage("No mersennes found");

			for (Pow2Result Result : Results)
				Utils::PrintMessage(Result.Summary());

		}
	/*	mpir_ui StartRange = std::min(atoi(argv[1]), atoi(argv[2]));
		mpir_ui EndRange = std::max(atoi(argv[1]), atoi(argv[2]));

		std::vector<Pow2Result> Results;
		MersennePrimes mp(StartRange, EndRange, argc > 3);
		mp.GenerateListOfMersennes();
		Results = mp.GetResults();

		if (Results.size() == 0)
			Utils::PrintMessage("No mersennes found");*/

		/*for (Pow2Result Result : Results)
			Utils::PrintMessage(Result.Summary());*/

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

static void GetData()
{
	std::string ConnectionString = "host=nuc port=5432 dbname=commands user=postgres password=Giraffes09";
	pqxx::connection PGConnection = pqxx::connection(ConnectionString);
	//PGConnection.prepare("getprimes", "select getprimes()");
	pqxx::transaction txn(PGConnection);
	/*pqxx::result r(txn.exec_prepared("getprimes"));

	Primes = std::vector<int>(r.begin(), r.end());*/

	for (auto [Prime] : txn.stream<int>("select getprimes()"))
	{
		Primes.push_back(Prime);
	}

	/*for(auto [Prime] : r.begin().as<int>())
	{
		Primes.push_back(Prime);
	}*/
	txn.commit();
}

