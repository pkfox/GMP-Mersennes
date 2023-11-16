#include "PrimeStatus.h"

// This method returns the prime probability as returned by GMP.
std::string PrimeStatus::GetStatus(int PrimeProbability)
{
	if (PrimeStatuses.size() == 0)
		InitMap();

	return PrimeStatuses[PrimeProbability];
}

void PrimeStatus::InitMap()
{
	PrimeStatuses.insert(std::pair<int, std::string>(0, " is definitely not a prime"));
	PrimeStatuses.insert(std::pair<int, std::string>(1, " is possibly a prime"));
	PrimeStatuses.insert(std::pair<int, std::string>(2, " is definitely a prime"));
}

