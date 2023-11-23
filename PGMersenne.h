#ifndef PGMERSENNE_H
#define PGMERSENNE_H
#include <pqxx/pqxx>
#include <string>
#include <sstream>
#include <iostream>
#include "PrimeStatus.h"

class PGMersenne
{
public:
	PGMersenne(int primepower, std::string mersenneprime,int PrimeProbability);
	std::size_t EditMersenne();
	
private:
	int Primepower;
	std::string Mersenneprime;
	std::string ConnectionString = "host=nuc port=5432 dbname=commands user=postgres password=Giraffes09";
    int PrimeProbability;
	pqxx::connection PGConnection = pqxx::connection(this->ConnectionString);
};
#endif

