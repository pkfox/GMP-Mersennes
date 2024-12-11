#include "Utils.h"

void Utils::PrintMessage(std::string msg)
{
	std::cout << msg << "\n";
}

std::string Utils::GetDateTime()
{
    time_t now = time(nullptr);
    // convert now to local time
    struct tm* local_time = localtime(&now);
    // convert local_time to string form
    std::string date_time(asctime(local_time));
    return date_time;
}