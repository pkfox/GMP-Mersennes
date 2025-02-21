#include <string>
#include <pqxx/pqxx>
#include <rapidjson/document.h>
#include <rapidjson/stringbuffer.h>
#include <rapidjson/writer.h>
#include "PrimeStatus.h"

<<<<<<< HEAD

//namespace pjk
//{
	// Storage class for a Mersenne prime
	class MersennePrime
	{
	public:
		MersennePrime();
		MersennePrime(int Mersenne,
		std::string MersenneResult,
		int PrimeProbability,std::string Duration);

		std::string GetJSON();
		int Mersenne;
		std::string MersenneResult;
		int PrimeProbability;
		std::string PrimeProbabilityText;
		std::string Duration;
	};
//}
=======
// Storage class for a Mersenne prime
class MersennePrime
{
public:
	MersennePrime();
	MersennePrime(int Mersenne, std::string MersenneResult, int PrimeProbability);
	std::string GetJSON();
	int Mersenne;
	std::string MersenneResult;
	int PrimeProbability;
	std::string PrimeProbabilityText;
};

>>>>>>> a9eb77f3be0f0d51cbdb9807717e538655eb21e4

