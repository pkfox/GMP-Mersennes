#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <iostream>

namespace pqxx
{
	class Utils
	{
	public:
		static void PrintMessage(std::string msg,int OptionalNumber = -1);
	};
}
#endif


