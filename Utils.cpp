#include "Utils.h"
constexpr auto BUFSIZE = 48;

void Utils::PrintMessage(std::string msg)
{
	std::cout << GetDateTime() << " " << msg << "\n";
}

std::string Utils::GetDateTime()
{
    struct tm newtime;
    __time32_t aclock;
    char buffer[BUFSIZE];
    errno_t errNum;
    _time32(&aclock);   // Get time in seconds.
    _localtime32_s(&newtime, &aclock);   // Convert time to struct tm form.

    // local time as a string.
    errNum = asctime_s(buffer, BUFSIZE, &newtime);
    std::string RetVal(buffer);
    RetVal.pop_back(); // remove line ending.
 
     return RetVal;
}
