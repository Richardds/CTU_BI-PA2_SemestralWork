#include "Logger.h"

void SW::Logger::Info(const std::string & message) {
    std::cout << "[  INFO ]" << Logger::makeHeader() << message << std::endl;
}

void SW::Logger::Debug(const std::string & message, const SW::Trace & trace) {
    std::cout << "[ DEBUG ]" << Logger::makeHeader(trace) << message << std::endl;
}

void SW::Logger::Error(const std::string & message, const SW::Trace & trace) {
    std::cerr << "[ ERROR ]" << Logger::makeHeader(trace) << message << std::endl;
}

std::string SW::Logger::makeHeader() {
    std::ostringstream oss;
    oss << std::setfill(' ') << std::setw(10) << SDL_GetTicks();
    return "[ " + oss.str() + " ] ";
}

std::string SW::Logger::makeHeader(const SW::Trace & trace) {
    std::ostringstream oss;
    oss << std::setfill(' ') << std::setw(10) << SDL_GetTicks();
    return "[ " + oss.str() + " ] " + trace.toString() + ": ";
}
