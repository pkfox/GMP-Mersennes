#include "PrimeStatus.h"

PrimeStatus::PrimeStatus()
{
	this->PrimeStatuses.insert(std::pair<int, std::string>(0, " is definitely not a prime"));
	this->PrimeStatuses.insert(std::pair<int, std::string>(1, " is possibly a prime"));
	this->PrimeStatuses.insert(std::pair<int, std::string>(2, " is definitely a prime"));
}

// This method returns the prime probability as returned by GMP.
std::string PrimeStatus::GetStatus(int PrimeProbability)
{
	return this->PrimeStatuses[PrimeProbability];
}
