#include "logger.h"

struct TextColor
{
    const char *red = "\033[31m", *lightRed = "\033", *orange = "\033", *yellow = "\033", *green = "\033",
               *blue = "\033", *lightBlue = "\033", *resetColor = "\033[0";
};

namespace logger {

void _log(const char *color, const char *msg)
{
}

void LogProblem(LogLevel logLevel, const char *msg)
{
    switch (logLevel)
    {
    case LogLevel::fatal:
        std::cout << "\033[33;3m[FATAL]: " << __FILE__ << __LINE__ << msg << std::endl;
        break;
    case LogLevel::error:
        std::cout << "\033[22;2m[ERROR]: " << __FILE__ << __LINE__ << msg << std::endl;
        break;
    case LogLevel::warning:
        std::cout << "\033[11;2m[WARNING]: " << __FILE__ << __LINE__ << msg << std::endl;
        break;
    default:
        break;
    }
}

void LogInfo(const char *msg)
{
    std::cout << "\033[44;1m[INFO]: " << msg << std::endl;
}

void LogDebug(LogLevel logLevel, char *msg)
{
    switch (logLevel)
    {
    case LogLevel::debug:
        std::cout << "\033[11;1m[DEBUG]: " << __FILE__ << __LINE__ << msg << std::endl;
        break;
    case LogLevel::trace:
        std::cout << "\033[11;1m[TRACE]: " << msg << std::endl;
    default:
        break;
    }
}
} // namespace logger