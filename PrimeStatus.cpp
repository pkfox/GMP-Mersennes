#include "PrimeStatus.h"
namespace pqxx
{
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
        std::ifstream file("mersennestatuses.txt");
        int i = 0;
        std::string line;
        for (; getline(file, line); i++)
        {
            PrimeStatuses[i] = line;
            PrimeStatusMessages[i] = " is " + line;
        }
        file.close();
    }
}
