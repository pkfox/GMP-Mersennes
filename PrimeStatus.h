#ifndef PRIMESTATUS_H
#define PRIMESTATUS_H
#include <string>
#include <map>
#include <sstream>
#include <iostream>
#include <istream>
#include <fstream>

#include "rapidjson/document.h"

class PrimeStatus
{
public:
    static std::string GetStatus(int PrimeProbability);
    static std::string GetStatusMessage(int PrimeProbability);
    struct PrimeInfo
    {
        std::string status;
        std::string message;
    };

private:
    static inline std::map<int, PrimeInfo> PrimeStatusMap;
    static void InitMap();
    static bool Mapinitialized;
};

#endif