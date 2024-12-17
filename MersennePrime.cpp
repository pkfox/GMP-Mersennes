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
    std::string RetVal;
    rapidjson::StringBuffer strbuf;
    rapidjson::Writer<rapidjson::StringBuffer> writer(strbuf);

    writer.StartObject();
    writer.String("Mersenne");
    writer.Int(this->Mersenne);

    writer.String("MersenneResult");
    writer.String(this->MersenneResult.c_str());

    writer.String("PrimeProbability");
    writer.Int(this->PrimeProbability);

    writer.String("PrimeProbabilityText");
    writer.String(this->PrimeProbabilityText.c_str());

    writer.EndObject();
    RetVal = strbuf.GetString();
    return RetVal;
}

