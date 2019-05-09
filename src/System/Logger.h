#ifndef SEMESTRALWORK_LOGGER_H
#define SEMESTRALWORK_LOGGER_H

#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <SDL2/SDL.h>
#include "Trace.h"

namespace SW {
    class Logger {
    public:
        static void Info(const std::string & message);
        static void Debug(const std::string & message, const Trace & trace);
        static void Internal(const std::string & message);
        static void Error(const std::string & message, const Trace & trace);

    private:
        static std::string makeHeader();
        static std::string makeHeader(const Trace & trace);
    };
}

#endif
