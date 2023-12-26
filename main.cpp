#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <iterator>
#include "MersennePrimes.h"
#include <chrono>
#include <algorithm>
#include "Utils.h"
#include <algorithm>
#include <regex>

using namespace pqxx;

int main(int argc, char* argv[])
{
	std::regex confirm_regex("Y", std::regex_constants::icase);
	std::regex primality_regex("-C", std::regex_constants::icase);

	std::vector<std::string> Args(argv + 1, argv + argc);
	int StartRange;
	int EndRange;
	std::vector<int> Primes;
	auto beg = std::chrono::high_resolution_clock::now();
	PGMersenne pgm;
	std::string Confirm;
	bool CheckPrimality = std::regex_search(argc > 1 ? argv[1] : "",primality_regex);
	std::stringstream ss;
	ss << "Mersenne search will " << (CheckPrimality ? "apply" : "skip") << " the primality test\n";
	ss << "Do you want to continue Y/N ? ";

	std::cout << ss.str();
	std::getline(std::cin, Confirm);

	if (!std::regex_search(Confirm, confirm_regex))
		return -1;

	pgm.GetData(Primes);

	for (size_t i = 0; i < Primes.size(); i++)
	{
		StartRange = Primes[i] - 1;
		EndRange = Primes[i];
		MersennePrimes mp(StartRange, EndRange, CheckPrimality);
		mp.GenerateListOfMersennes();
	}

	auto end = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::minutes>(end - beg);
	std::cout << "Elapsed Time: " << duration.count() << " minutes\n";
	return 0;
}







