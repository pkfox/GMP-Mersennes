#include "PrimeStatus.h"

bool PrimeStatus::Mapinitialized = []() 
{
    InitMap();  // Automatically load data at program start
    return true;
}();


void PrimeStatus::InitMap()
{
    std::ifstream file("mersennestatuses.json");
    std::stringstream buffer;
    buffer << file.rdbuf();
    file.close();

    rapidjson::Document doc;
    doc.Parse(buffer.str().c_str());

    if (!doc.HasMember("Mersennestatuses") || !doc["Mersennestatuses"].IsArray())
        return;

    const rapidjson::Value& statuses = doc["Mersennestatuses"];

    for (rapidjson::SizeType i = 0; i < statuses.Size(); i++)
    {
        const rapidjson::Value& item = statuses[i];
        int id = item["id"].GetInt();

        PrimeInfo info;
        info.status = item["status"].GetString();
        info.message = item["message"].GetString();

        PrimeStatusMap[id] = info;
    }
}

std::string PrimeStatus::GetStatus(int PrimeProbability)
{
    return PrimeStatusMap[PrimeProbability].status;
}

std::string PrimeStatus::GetStatusMessage(int PrimeProbability)
{
    return PrimeStatusMap[PrimeProbability].message;
}