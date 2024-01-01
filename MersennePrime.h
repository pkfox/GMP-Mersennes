#include <string>
#include <pqxx/pqxx>


namespace pjk
{
	// Storage class for a Mersenne prime
	class MersennePrime
	{
	public:
		int Mersenne;
		std::string MersenneResult;
		int PrimeProbability;
	};
}

