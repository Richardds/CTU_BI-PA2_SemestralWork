#ifndef SEMESTRALWORK_WINDOW_H
#define SEMESTRALWORK_WINDOW_H

#include <string>
#include "SDL.h"

namespace SW {
    class Window {
    public:
        Window(int width, int height, const std::string & title = "Title");
        ~Window();
        bool initialize();
        void destroy();
        SDL_Window * getSDLWindow() const;
        const std::string & getTitle() const;
        void setTitle(const std::string & title);
        int getWidth() const;
        void setWidth(int width);
        int getHeight() const;
        void setHeight(int height);

        static const int DEFAULT_WIDTH = 805;
        static const int DEFAULT_HEIGHT = 630;

    private:
        SDL_Window * _window;
        std::string _title;
        int _width;
        int _height;
    };
}

#endif
