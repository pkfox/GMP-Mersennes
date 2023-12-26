#ifndef PGMERSENNE_H
#define PGMERSENNE_H
#include <pqxx/pqxx>
#include <gmpxx.h>
#include <string>
#include <sstream>
#include <iostream>
#include "PrimeStatus.h"
#include "Utils.h"

namespace pjk
{
	class PGMersenne
	{
	public:
		PGMersenne(PGMersenne& mp);
		PGMersenne();
		PGMersenne(int Mersenne, std::string MersenneResult, int Probability);
		[[nodiscard]]
		std::size_t EditMersenne();
		void GetData(std::vector<int>& Primes);
	private:
		int Mersenne;
		std::string MersenneResult;
		int Probability;
		std::string PrimeProbabilityText;
		std::string ConnectionString = "host=nuc port=5432 dbname=commands user=postgres password=Giraffes09";
		pqxx::connection PGConnection = pqxx::connection(this->ConnectionString);
		pqxx::work PGTransaction = pqxx::work(PGConnection);
		pqxx::result PGResult;
	};

#endif
}
