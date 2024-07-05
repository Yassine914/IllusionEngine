#include "logger.h"

#define TEXT_RED "\x1b[31m"
#define TEXT_GREEN "\x1b[32m"
#define TEXT_YELLOW "\x1b[33m"
#define TEXT_BLUE "\x1b[34m"
#define TEXT_PURPLE "\x1b[35m"
#define TEXT_CYAN "\x1b[36m"
#define TEXT_RESET_COLOR "\x1b[0m"

namespace logger {

std::string colorize(const char *color, const char *text)
{
    std::string coloredText = color;
    coloredText.append(text).append(TEXT_RESET_COLOR);

    return coloredText;
}

void _log(const char *color, const char *msg, bool fileName, bool lineNumber, bool timed)
{
    std::cout << color;

    if(timed) // TODO: add timing (need to run a timer on a seperate thread...)
        std::cout << "";

    if(fileName && lineNumber)
        std::cout << "";
    else if(fileName)
        std::cout << "";
}

void LogProblem(LogLevel logLevel, const char *msg)
{
    switch(logLevel)
    {
    case LogLevel::fatal:
        std::cout << colorize(TEXT_RED, msg);
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
    std::cout << "[" << colorize(TEXT_PURPLE, "INFO");
    std::cout << "]: " << colorize(TEXT_PURPLE, msg) << std::endl;
}

void LogDebug(LogLevel logLevel, char *msg)
{
    switch(logLevel)
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