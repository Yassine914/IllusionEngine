#include <iostream>
#include <string>

enum class LogLevel
{
    fatal,
    error,
    warning,
    info,
    debug,
    trace
};

namespace logger {

void LogProblem(LogLevel logLevel, const char *msg);
void LogInfo(const char *msg);
void LogDebug(LogLevel logLevel, char *msg);
} // namespace logger