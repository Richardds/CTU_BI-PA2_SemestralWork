#ifndef SEMESTRALWORK_CORE_H
#define SEMESTRALWORK_CORE_H

#include <cstdint>
#include "SDL.h"
#include "../System/Trace.h"
#include "../System/Logger.h"

#define _Info(message)  (SW::Logger::Info(message))
#define _Internal(message) (SW::Logger::Internal(message))
#define _Debug(message) (SW::Logger::Debug(message, SW::Trace(__FILE__,__LINE__,__PRETTY_FUNCTION__)))
#define _Error(message) (SW::Logger::Error(message, SW::Trace(__FILE__,__LINE__,__PRETTY_FUNCTION__)))

namespace SW {
    template<typename T> std::string toSignedNumberString(T number) {
        return (number >= 0 ? "+" : "") + std::to_string(number);
    }

    namespace Magic {
        const uint32_t BUILDING_CONFIG = SDL_FOURCC('B', 'C', 'F', 'G');
    }
}

#endif
