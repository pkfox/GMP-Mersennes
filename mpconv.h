#ifndef MPCONV_H
#define MPCONV_H

#include <pqxx/pqxx>
#include "MersennePrime.h"

namespace pqxx
{
	template<> struct nullness<pjk::MersennePrime>:no_null<pjk::MersennePrime>{};
	template<> struct string_traits<pjk::MersennePrime>
	{
		bool converts_to_string{ true };
		bool converts_from_string{ true };
	};
}
#endif


