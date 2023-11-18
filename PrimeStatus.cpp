#include "PrimeStatus.h"

std::string PrimeStatus::GetStatus(int PrimeProbability)
{
   if (PrimeStatuses.size() == 0)
      InitMap();

   return PrimeStatuses.count(PrimeProbability) > 0 ? PrimeStatuses[PrimeProbability]:"No status found";
}

void PrimeStatus::InitMap()
{
   std::ifstream file("mersennestatuses.txt");
   int i = 0;
   for(std::string line;getline(file,line);)
    {
       PrimeStatuses.insert(std::pair<int, std::string>(i,line));
       std::cout << line << "\n";
       ++i;
    }
    file.close();
}

