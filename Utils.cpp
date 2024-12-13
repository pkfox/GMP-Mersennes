#include "Utils.h"

void Utils::PrintMessage(std::string msg)
{
	std::cout << GetDateTime() << " " << msg << "\n";
}

std::string Utils::GetDateTime()
{
    struct tm newtime;
    __time32_t aclock;
    char buffer[32];
    errno_t errNum;
    _time32(&aclock);   // Get time in seconds.
    _localtime32_s(&newtime, &aclock);   // Convert time to struct tm form.

    // local time as a string.
    errNum = asctime_s(buffer, 32, &newtime);
    return std::string(buffer);
}
