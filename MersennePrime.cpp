#include "MersennePrime.h"

pjk::MersennePrime::MersennePrime():Mersenne(0),MersenneResult(""),PrimeProbability(0),PrimeProbabilityText("")
{

}

pjk::MersennePrime::MersennePrime(int Mersenne, std::string MersenneResult, int PrimeProbability):MersennePrime()
{
	this->Mersenne = Mersenne;
	this->MersenneResult = MersenneResult;
	this->PrimeProbability = PrimeProbability;
	this->PrimeProbabilityText = PrimeStatus::GetStatusMessage(this->PrimeProbability);
}

std::string pjk::MersennePrime::GetJSON()
{
    using namespace rapidjson;

        StringBuffer strbuf;
        Writer<StringBuffer> writer(strbuf);
      
        writer.String("Mersenne");
        writer(Mersenne);
        writer.EndObject();
        return strbuf.GetString();
}

