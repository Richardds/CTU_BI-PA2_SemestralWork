#ifndef SEMESTRALWORK_SEMESTRALWORK_H
#define SEMESTRALWORK_SEMESTRALWORK_H

#include "Core/core.h"
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
        void handleEvent();

    private:
        Window _window;
        Renderer _renderer;
        GameLogic _game;
        bool _close;
    };
}

#endif
