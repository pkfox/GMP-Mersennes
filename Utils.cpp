#include "Utils.h"

constexpr auto BUFSIZE = 48;

void Utils::PrintMessage(std::string msg)
{
	std::cout << GetDateTime() << " " << msg << "\n";
}


std::string Utils::GetDateTime()
{
    time_t now = time(nullptr);
    // convert now to local time
    struct tm* local_time = localtime(&now);
    // convert local_time to string form
    std::string date_time(asctime(local_time));
    date_time.pop_back();
    return date_time;
}

std::string Utils::Pluralise(std::string Word, int Number)
{
    return Number == 0 || Number > 1 ? Word.append("s") : Word;
}