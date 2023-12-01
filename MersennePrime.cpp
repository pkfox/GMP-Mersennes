#include "MersennePrime.h"


MersennePrime::MersennePrime():PrimeProbability(0),Prime(0)
{
}


MersennePrime::MersennePrime(mpir_ui Prime, std::string Result, int PrimeProbability)
{
	this->Prime = Prime;
	this->Result = Result;
	this->PrimeProbability = PrimeProbability;
}
