#include "PrimeStatus.h"

	std::string PrimeStatus::GetStatus(int PrimeProbability)
	{
		std::string RetVal;

		if (PrimeStatuses.size() == 0)
			InitMap();

		return PrimeStatuses.count(PrimeProbability) > 0 ? PrimeStatuses[PrimeProbability] : RetVal;
	}

	std::string PrimeStatus::GetStatusMessage(int PrimeProbability)
	{
		std::string RetVal;

		if (PrimeStatusMessages.size() == 0)
			InitMap();

		return PrimeStatusMessages.count(PrimeProbability) > 0 ? PrimeStatusMessages[PrimeProbability] : RetVal;
	}

	void PrimeStatus::InitMap()
	{
		std::ifstream statusfile("mersennestatuses.txt");
		std::ifstream messagefile("mersennemessages.txt");
		int i = 0;
		std::string line;
		
		for (; getline(statusfile, line); i++)
		{
			PrimeStatuses[i] = line;
		}
		statusfile.close();
		
		i = 0;
		line = "";
		
		for (; getline(messagefile, line); i++)
		{
			PrimeStatusMessages[i] = line;
		}
		messagefile.close();
	}