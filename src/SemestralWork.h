#ifndef SEMESTRALWORK_SEMESTRALWORK_H
#define SEMESTRALWORK_SEMESTRALWORK_H

#include "Core/core.h"
#include "Core/Window.h"
#include "Core/Renderer.h"
#include "Game/GameLogic.h"

namespace SW {
    /**
     * Application backbone
     */
    class SemestralWork {
    public:
        /**
         * Application constructor
         * Also sets default windows title with author name.
         */
        SemestralWork();
        /**
         * Application destructor
         * Calls clean up methods.
         */
        ~SemestralWork();
        /**
         * Initializes application important subsystems.
         * @return
         */
        bool initialize();
        /**
         * Cleans up application resources.
         */
        void destroy();
        /**
         * @return true if application termination is requested, otherwise false
         */
        bool closeRequested();
        /**
         * Processes application handlers and game loop.
         */
        void loop();
        /**
         * Handles application core events.
         */
        void handleEvent();

    private:
        Window _window;
        Renderer _renderer;
        GameLogic _game;
        bool _close;
    };
}

#endif
