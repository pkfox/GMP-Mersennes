#include "MersennePrime.h"

MersennePrime::MersennePrime():Mersenne(0),MersenneResult(""),PrimeProbability(0),PrimeProbabilityText("")
{

}

<<<<<<< HEAD
MersennePrime::MersennePrime(int Mersenne, std::string MersenneResult,
 int PrimeProbability,std::string Duration):MersennePrime()
=======
MersennePrime::MersennePrime(int Mersenne, std::string MersenneResult, int PrimeProbability):MersennePrime()
>>>>>>> a9eb77f3be0f0d51cbdb9807717e538655eb21e4
{
	this->Mersenne = Mersenne;
	this->MersenneResult = MersenneResult;
	this->PrimeProbability = PrimeProbability;
	this->PrimeProbabilityText = PrimeStatus::GetStatusMessage(this->PrimeProbability);
	this->Duration = Duration;
}

std::string MersennePrime::GetJSON()
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
    
    writer.String("Duration");
    writer.String(this->Duration.c_str());

    writer.EndObject();
    RetVal = strbuf.GetString();
    return RetVal;
}
