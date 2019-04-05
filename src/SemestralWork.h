#ifndef SEMESTRALWORK_SEMESTRALWORK_H
#define SEMESTRALWORK_SEMESTRALWORK_H

#define SDL_MAIN_HANDLED

#include "SDL.h"
#include "Core/Window.h"
#include "Core/Renderer.h"
#include "Game/GameLogic.h"

namespace SW {
    class SemestralWork {
    public:
        SemestralWork();
        ~SemestralWork();
        bool initialize();
        void destroy();
        bool closeRequested();
        void loop();
        void clearDisplay();
        void handleCoreEvents();

    private:
        Window _window;
        Renderer _renderer;
        GameLogic _game;
        bool _close;
    };
}

#endif
