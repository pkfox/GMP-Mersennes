#ifndef PRIMESTATUS_H
#define PRIMESTATUS_H

#include <string>
#include<map>
#include <fstream>
#include <iostream>

class PrimeStatus
{
public:
	static std::string GetStatus(int PrimeProbability);
	static std::string GetStatusMessage(int PrimeProbability);
private:
	static inline std::map<int, std::string> PrimeStatuses;
	static inline std::map<int, std::string> PrimeStatusMessages;
	 static void InitMap();
};
#endif


