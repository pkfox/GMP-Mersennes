#include "PrimeStatus.h"

MyPrimeStatus::MyPrimeStatus()
{
	PrimeStatuses.insert(std::pair<int, std::string>(0, " is definitely not a prime"));
	PrimeStatuses.insert(std::pair<int, std::string>(1, " is possibly a prime"));
	PrimeStatuses.insert(std::pair<int, std::string>(2, " is definitely a prime"));
}



// This method returns the prime probability as returned by GMP.
std::string MyPrimeStatus::GetStatus(int PrimeProbability)
{
	return PrimeStatuses[PrimeProbability];
}

