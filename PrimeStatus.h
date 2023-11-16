#ifdef _WIN32
#pragma once
#endif

#include <string>
#include<map>

class PrimeStatus
{
public:
	static std::string GetStatus(int PrimeProbability);
private:
	static inline std::map<int, std::string> PrimeStatuses;
	static void InitMap();
};


