#include <string>
#include<map>

class MyPrimeStatus
{
public:
	MyPrimeStatus();
	static std::string GetStatus(int PrimeProbability);
private:
	static std::map<int, std::string> PrimeStatuses;
};


