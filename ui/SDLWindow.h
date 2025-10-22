#ifndef SDL_WINDOW_H
#define SDL_WINDOW_H

#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <memory>

class SDLWindow {
    private:
        SDL_Window* window;

        int windowWidth{0};
        int windowHeight{0};
        bool running{false};

    public:
        SDLWindow(int width, int height);
        ~SDLWindow();
        bool isRunning();
        void Quit();
};

#endif //SDL_WINDOW_H