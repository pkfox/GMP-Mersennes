#ifndef PGMERSENNE_H
#define PGMERSENNE_H
#include <pqxx/pqxx>
#include <string>
#include <sstream>
#include <iostream>
#include "PrimeStatus.h"
#include "MersennePrime.h"
#include <typeinfo> 
class PGMersenne
{
public:
	PGMersenne(MersennePrime mp);
	std::size_t EditMersenne();
private:
	MersennePrime Mersenneprime;
	std::string ConnectionString = "host=nuc port=5432 dbname=commands user=postgres password=Giraffes09";
	pqxx::connection PGConnection = pqxx::connection(this->ConnectionString);
};
#endif

