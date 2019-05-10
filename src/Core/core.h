#ifndef SEMESTRALWORK_CORE_H
#define SEMESTRALWORK_CORE_H

#include <cstdint>
#include <memory>
#include <SDL2/SDL.h>
#include "../System/Trace.h"
#include "../System/Logger.h"

#define _Info(message)  (SW::Logger::Info(message))
#define _Internal(message) (SW::Logger::Internal(message))
#define _Debug(message) (SW::Logger::Debug(message, SW::Trace(__FILE__,__LINE__,__PRETTY_FUNCTION__)))
#define _Error(message) (SW::Logger::Error(message, SW::Trace(__FILE__,__LINE__,__PRETTY_FUNCTION__)))

namespace SW {
    /**
     * x,y coordinates structure
     */
    struct Position {
        uint16_t x;
        uint16_t y;
    };

    /**
     * Converts number to string with sign symbol visible.
     * @tparam T
     * @param number
     * @return
     */
    template<typename T> std::string toStringShowSign(T number) {
        return (number >= 0 ? "+" : "") + std::to_string(number);
    }

    /**
     * Magic headers of application's binary files
     */
    namespace Magic {
        const uint32_t BUILDING_CONFIG = SDL_FOURCC('B', 'C', 'F', 'G');    // BuildingConFiG
        const uint32_t GAME_STATE = SDL_FOURCC('S', 'W', 'G', 'S');         // SemestralWorkGameState
    }
}

#endif
