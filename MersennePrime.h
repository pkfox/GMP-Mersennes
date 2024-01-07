#include <string>
#include <pqxx/pqxx>
#include <rapidjson/document.h>
#include <rapidjson/stringbuffer.h>
#include "PrimeStatus.h"


namespace pjk
{
	// Storage class for a Mersenne prime
	class MersennePrime
	{
	public:
		MersennePrime();
		MersennePrime(int Mersenne, std::string MersenneResult,int PrimeProbability);
		std::string GetJSON();
	private:
		int Mersenne;
		std::string MersenneResult;
		int PrimeProbability;
		std::string PrimeProbabilityText;
	};
}

