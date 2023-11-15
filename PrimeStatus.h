#pragma once
#include <string>
#include<map>

class PrimeStatus
{
public:
	PrimeStatus();
	std::string GetStatus(int PrimeProbability);
private:
	std::map<int, std::string> PrimeStatuses;
};


