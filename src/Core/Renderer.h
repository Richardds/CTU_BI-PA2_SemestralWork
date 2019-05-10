#ifndef SEMESTRALWORK_RENDERER_H
#define SEMESTRALWORK_RENDERER_H

#include <SDL2/SDL.h>
#include "Window.h"
#include "core.h"
#include "../Graphics/Entity.h"

namespace SW {
    class Entity;
    /**
     * SDL_Renderer wrapper with helper functions
     */
    class Renderer {
    public:
        /**
         * Constructor
         */
        Renderer();
        /**
         * Destructor
         */
        ~Renderer();
        /**
         * Initializes SDL_Renderer.
         * @param window SDL_Window wrapper
         * @return bool
         */
        bool initialize(const Window & window);
        /**
         * Cleans up SDL_Renderer resources.
         */
        void destroy();
        /**
         * Renders entity to screen.
         * @param entity Entity to be rendered
         */
        void render(const Entity * entity) const;
        /**
         * Flushes SDL_Renderer.
         */
        void update() const;
        /**
         * Sets default screen background color.
         * @param color Color to be used as background color
         */
        void setRenderingColor(SDL_Color color) const;
        /**
         * Calculates time delta and clears the rendering screen.
         */
        void prepare();
        /**
         * Returns current frame time.
         * @return double
         */
        double getFrameTime();
        /**
         * Returns pointer to SDL_Renderer instance.
         * @return
         */
        SDL_Renderer * getSDLRenderer() const;

        /**
         * Screen updates per second
         */
        static const int FPS = 60;

    private:
        SDL_Renderer * _renderer;
        uint32_t last_frame_time;
        double time_delta;
    };
}

#endif
