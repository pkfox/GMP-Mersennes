#include <string>

class MersennePrime
{
public:
	int Mersenne;
	std::string Result;
	int PrimeProbability;
};

namespace pqxx
{
	template<typename MersennePrime >
	std::string const type_name{ internal::demangle_type_name(typeid(MersennePrime).name("MersennePrime"))};
}