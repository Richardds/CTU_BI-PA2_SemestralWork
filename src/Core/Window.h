#ifndef SEMESTRALWORK_WINDOW_H
#define SEMESTRALWORK_WINDOW_H

#include <string>
#include <SDL2/SDL.h>

namespace SW {
    /**
     * SDL_Window wrapper with helper functions
     */
    class Window {
    public:
        /**
         * Contructor
         * @param width
         * @param height
         * @param title
         */
        Window(int width, int height, const std::string & title = "Title");
        /**
         * Destructor
         */
        ~Window();
        /**
         * Initializes SDL_Window.
         * @return true on success otherwise false
         */
        bool initialize();
        /**
         * Cleans up SDL_Window resources.
         */
        void destroy();
        /**
         * @return Pointer to SDL_Window
         */
        SDL_Window * getSDLWindow() const;
        /**
         * @return Window title
         */
        const std::string & getTitle() const;
        /**
         * Sets window title.
         * @param title
         */
        void setTitle(const std::string & title);
        /**
         * @return Window width
         */
        int getWidth() const;
        /**
         * Sets window width.
         * @param int
         */
        void setWidth(int width);
        /**
         * @return Window height
         */
        int getHeight() const;
        /**
         * Sets window height.
         * @param int
         */
        void setHeight(int height);

        /**
         * Window width set by default
         */
        static const int DEFAULT_WIDTH = 860;
        /**
         * Window height set by default
         */
        static const int DEFAULT_HEIGHT = 680;

    private:
        SDL_Window * _window;
        std::string _title;
        int _width;
        int _height;
    };
}

#endif
