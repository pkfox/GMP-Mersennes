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
	std::string ConnectionString;
	int EditMersenne();
private:
	int Primepower;
	std::string Mersenneprime;
};
#endif

