#ifndef PGMERSENNE_H
#define PGMERSENNE_H
#include <pqxx/pqxx>
#include <string>
#include <sstream>
#include <iostream>
#include "PrimeStatus.h"
#include <typeinfo> 
class PGMersenne
{
public:
	PGMersenne(int Mersenne,std::string MersenneResult,int Probability);
	std::size_t EditMersenne();
private:
	int Mersenne;
	std::string MersenneResult;
	int Probability;
	std::string PrimeProbabilityText;
	std::string ConnectionString = "host=nuc port=5432 dbname=commands user=postgres password=Giraffes09";
	pqxx::connection PGConnection = pqxx::connection(this->ConnectionString);
};
#endif

