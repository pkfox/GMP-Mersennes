#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <iostream>

class Utils
{
public:
	static void PrintMessage(std::string msg);
	static std::string GetDateTime();
	static std::string Pluralise(std::string Word, int Number);
};
#endif


