#include <chrono>
// This is largely jtv's code
// posted 08-04-2025

namespace pqxx
{
    template<>
    std::string const type_name<std::chrono::hh_mm_ss<std::chrono::seconds>>
    {
        "Eat shit"
    };

    template<> struct nullness<std::chrono::hh_mm_ss<std::chrono::seconds>> :
        no_null<std::chrono::hh_mm_ss<std::chrono::seconds>>
    {
    };


    template<> struct string_traits<std::chrono::hh_mm_ss<std::chrono::seconds>>
    {
        using time_type = std::chrono::hh_mm_ss<std::chrono::seconds>;

        static constexpr bool converts_to_string{ true };
        static constexpr bool converts_from_string{ true };

        static inline std::size_t size_buffer(time_type const& value) noexcept
        {
            return 9 + std::size_t(value.is_negative());
        }

        static inline zview to_buf(char* begin, char* end, time_type const& value)
        {
            return generic_to_buf(begin, end, value);
        }

        static inline time_type from_string(std::string value)
        {
            int h, m, s;
            char sep1, sep2;
            std::istringstream iss(std::string{ value });

            if (!(iss >> h >> sep1 >> m >> sep2 >> s) || sep1 != ':' || sep2 != ':')
            {
                throw std::runtime_error("Invalid time format: you must delimit the numbers with : " + std::string{ value });
            }

            return std::chrono::hh_mm_ss<std::chrono::seconds>{ std::chrono::hours{h} + std::chrono::minutes{m} + std::chrono::seconds{s}};
        }

        // [[nodiscard]] removed by PJ Kane
        // 08-04-2025
        // as I don't think it's required.
        static inline std::string to_string(std::chrono::hh_mm_ss<std::chrono::seconds> value)
        {
            std::stringstream ss;
            ss << value.hours().count() << "h" << value.minutes().count() << "m" << value.seconds().count() << "s";
            return ss.str();
        }

        static char* into_buf(char* begin, char* end, time_type const& value)
        {
            auto const space = std::size_t(end - begin);
            auto const budget = size_buffer(value);
            if (space < budget)
                throw conversion_overrun{ "Not enough buffer space." };

            auto text = std::format("{}", value);
            if (std::size(text) >= budget)
                throw conversion_overrun{
                  std::format("Time does not fit into buffer: {}", text) };
            auto len = text.copy(begin, std::string::npos);
            begin[len] = '\0';
            return &begin[len + 1];
        }
    };
} 