#include <pqxx/pqxx>
#include <chrono>
#include <iomanip>
#include <sstream>
#include <string>
#include <stdexcept>


namespace pqxx
{
    template<>
    struct string_traits<std::chrono::hh_mm_ss<std::chrono::seconds>>
    {
        using TimeType = std::chrono::hh_mm_ss<std::chrono::seconds>;

        static constexpr std::string const name() noexcept
        {
            return "A_CONSTANT_NAME";
        }

        static constexpr bool has_null() noexcept
        {
            return false;
        }
        
        static constexpr bool is_null() noexcept
        {
            return false;
        }

        static TimeType from_string(std::string_view text)
        {
            int h, m, s;
            char sep1, sep2;
            std::istringstream iss(std::string{ text });

            if (!(iss >> h >> sep1 >> m >> sep2 >> s) || sep1 != ':' || sep2 != ':')
            {
                throw std::runtime_error("Invalid time format: " + std::string{ text });
            }

            using namespace std::chrono;
            return TimeType{ hours{h} + minutes{m} + seconds{s} };
        }

        static std::string to_string(TimeType const& t)
        {
            std::ostringstream oss;
            oss << std::setfill('0')
                << std::setw(2) << t.hours().count() << ":"
                << std::setw(2) << t.minutes().count() << ":"
                << std::setw(2) << t.seconds().count();
            return oss.str();
        }
    };
}

