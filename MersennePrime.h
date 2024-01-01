#include <string>
#include <pqxx/pqxx>

//namespace pqxx
//{
//	template<>
//	std::string const type_name<pjk::MersennePrime>{"MersennePrime"};
//	template<> struct nullness<pjk::MersennePrime> : no_null<pjk::MersennePrime> {};
//
//}

namespace pjk
{
	class MersennePrime
	{
	public:
		int Mersenne;
		std::string Result;
		int PrimeProbability;
	};
}
