#ifndef MPCONV_H
#define MPCONV_H
#include <pqxx/pqxx>
#include "MersennePrime.h"

namespace pqxx
{
	template<> struct nullness<pjk::MersennePrime>:no_null<pjk::MersennePrime>{};
	template<> struct string_traits<pjk::MersennePrime>
	{
		const bool converts_to_string{ false };
	    const bool converts_from_string{ false };
	    zview to_buf(char* begin, char* end, pjk::MersennePrime const& value);
		char* into_buf(char* begin, char* end, pjk::MersennePrime const& value);
		std::size_t size_buffer(pjk::MersennePrime const& value) noexcept;
	    pjk::MersennePrime from_string(std::string_view text);
	};

	zview string_traits<pjk::MersennePrime>::to_buf(char* begin, char* end, pjk::MersennePrime const& value)
	{
		return zview();
	}

	char* string_traits<pjk::MersennePrime>::into_buf(char* begin, char* end, pjk::MersennePrime const& value)
	{
	   return nullptr;
	}

	std::size_t string_traits<pjk::MersennePrime>::size_buffer(pjk::MersennePrime const& value) noexcept
	{
		size_t RetVal = to_string(value.Mersenne).length();
		RetVal += value.MersenneResult.length();
		RetVal += sizeof(value.PrimeProbability);
		return RetVal;
	}
}
#endif


