#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <iterator>
#include "MersennePrimes.h"
#include <chrono>
#include <algorithm>
#include "Utils.h"
#include <regex>

#include <pqxx/pqxx>
#include <exception>

int main(int argc, char* argv[])
{
	std::regex confirm_regex("Y", std::regex_constants::icase);
	std::regex primality_regex("-C", std::regex_constants::icase);
	std::vector<std::string> Args(argv + 1, argv + argc);
	std::vector<int> Primes;
	auto beg = std::chrono::high_resolution_clock::now();
	pjk::PGMersenne pgm;
	std::string Confirm;
	bool CheckPrimality = std::regex_search(argc > 1 ? argv[1] : "", primality_regex);
	std::stringstream ss;
	ss << "Mersenne search will " << (CheckPrimality ? "apply" : "skip") << " the primality test\n";
	ss << "Do you want to continue Y/N ? ";
	Utils::PrintMessage(ss.str());
	std::getline(std::cin, Confirm);

	if (!std::regex_search(Confirm, confirm_regex))
		return -1;

	pgm.GetData(Primes);
	pjk::MersennePrimes mp;

	mp.SetPrimalityCheck(CheckPrimality);

	for (size_t i = 0; i < Primes.size(); i++)
	{
		mp.SetStartRange(Primes[i] - 1);
		mp.SetEndRange(Primes[i]);
		mp.GenerateListOfMersennes();
	}

	auto end = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::minutes>(end - beg);
	
	ss.clear();
	ss.str("");
	ss << "Elapsed Time: " << duration.count() << " minutes";
	Utils::PrintMessage(ss.str());
	return 0;
}








