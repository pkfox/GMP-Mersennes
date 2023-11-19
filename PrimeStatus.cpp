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
   std::string line;
   for(;getline(file,line); i++)
   {
	  PrimeStatuses[i] = line;
   }
    file.close();
}

