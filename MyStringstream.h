#include <sstream>
#include <string>

class MyStringstream : public std::stringstream
{
public:
    MyStringstream();
    MyStringstream(std::string);
};

