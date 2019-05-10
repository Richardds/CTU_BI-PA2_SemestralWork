#ifndef SEMESTRALWORK_LOGGER_H
#define SEMESTRALWORK_LOGGER_H

#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <SDL2/SDL.h>
#include "Trace.h"

namespace SW {
    /**
     * Logs application behavior to console.
     */
    class Logger {
    public:
        /**
         * Prints informative message to console.
         * @param message
         */
        static void Info(const std::string & message);
        /**
         * Prints debug message to console. Trace is included.
         * @param message
         */
        static void Debug(const std::string & message, const Trace & trace);
        /**
         * Prints internal message to console.
         * @param message
         */
        static void Internal(const std::string & message);
        /**
         * Prints error message to console. Trace is included.
         * @param message
         */
        static void Error(const std::string & message, const Trace & trace);

    private:
        /**
         * Generates message prefix which includes time and message type.
         * @return Generated prefix
         */
        static std::string makeHeader();
        /**
         * Generates message prefix which includes time, message type and trace.
         * @param trace Calling trace
         * @return Generated prefix
         */
        static std::string makeHeader(const Trace & trace);
    };
}

#endif
