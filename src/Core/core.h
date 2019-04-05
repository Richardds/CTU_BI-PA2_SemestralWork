#ifndef SEMESTRALWORK_CORE_H
#define SEMESTRALWORK_CORE_H

#include "../System/Trace.h"

#define _Info(message)  (SW::Logger::Info(message))
#define _Debug(message) (SW::Logger::Debug(message, SW::Trace(__FILE__,__LINE__,__PRETTY_FUNCTION__)))
#define _Error(message) (SW::Logger::Error(message, SW::Trace(__FILE__,__LINE__,__PRETTY_FUNCTION__)))

namespace SW {
    struct Color {
        Color() : r(0), g(0), b(0), a(255)  {
            //
        }
        Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a = 255) : r(r), g(g), b(b), a(a) {
            //
        }
        uint8_t r;
        uint8_t g;
        uint8_t b;
        uint8_t a;
    };
}

#endif
