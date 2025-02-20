#ifndef PGMERSENNE_H
#define PGMERSENNE_H
#include <pqxx/pqxx>
#include <gmpxx.h>
#include <string>
#include <sstream>
#include <iostream>
#include "PrimeStatus.h"
#include "Utils.h"
#include "MersennePrime.h"


	class PGMersenne
	{
	public:
		PGMersenne();
		PGMersenne(int Mersenne, std::string MersenneResult, int Probability,std::string Duration);
		[[nodiscard]]
		std::size_t EditMersenne();
		void GetData(std::vector<int>& Primes);
	private:
		int Mersenne;
		std::string MersenneResult;
		int Probability;
		std::string PrimeProbabilityText;
		std::string Duration;
		std::string ConnectionString = "host=beelink port=5432 dbname=commands user=postgres password=Giraffes09";
		pqxx::connection PGConnection = pqxx::connection(this->ConnectionString);
		pqxx::work PGTransaction = pqxx::work(PGConnection);
		pqxx::result PGResult;
		pqxx::params Params;
	};
#endif

