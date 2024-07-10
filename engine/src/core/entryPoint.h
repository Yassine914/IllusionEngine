#pragma once

#include "logger.h"

#ifdef IPLATFORM_WINDOWS
extern Illusion::App *CreateApp();

int main(int argc, char **argv)
{
    Logger::LogToConsole(LogLevel::info, "Welcome to Illusion Engine.");
    auto app = Illusion::CreateApp();
    app->Run();
    delete app;
}
#endif