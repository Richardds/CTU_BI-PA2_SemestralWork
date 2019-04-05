#ifndef SEMESTRALWORK_GAMELOGIC_H
#define SEMESTRALWORK_GAMELOGIC_H

#include "../Core/Window.h"
#include "../Core/Renderer.h"
#include "../Graphics/Rectangle.h"
#include "../Core/core.h"
#include "../System/Logger.h"

namespace SW {
    class GameLogic {
    public:
        GameLogic();
        void process(const Renderer & renderer, const Window & window);

        static const uint32_t TICK_DEFUALT = 1000;

    private:
        bool tick();
        uint32_t _tick;
        uint32_t _tick_last;
    };
}

#endif
