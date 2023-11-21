#ifndef PGMERSENNE_H
#define PGMERSENNE_H
#include <pqxx/pqxx>
#include <string>
#include <sstream>
#include <iostream>

class PGMersenne
{
public:
	PGMersenne(int primepower, std::string mersenneprime);
	std::size_t EditMersenne();

private:
	int Primepower;
	std::string Mersenneprime;
	std::string ConnectionString;
	//pqxx::connection PGConnection;
};
#endif

