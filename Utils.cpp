#include "Utils.h"

namespace pqxx
{
	void Utils::PrintMessage(std::string msg, int OptionalNumber)
	{
		if (OptionalNumber >= 0)
			std::cout << OptionalNumber << " ";
		   
		std::cout << msg << "\n";
	}
}
