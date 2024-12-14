#include "Utils.h"

constexpr auto BUFSIZE = 48;

void Utils::PrintMessage(std::string msg)
{
    std::cout << GetDateTime() << " " << msg << "\n";
}

/*std::string Utils::GetDateTime()
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
*/

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

