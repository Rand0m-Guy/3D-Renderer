#include "ui/sdl_window.h"
#include "core/renderer/renderer.h"
#include <iostream>

int main(int argc, char* argv[]) {
    try {
        int width = 640;
        int height = 480;
        SDLWindow window(width, height);
        Renderer renderer(window);
        Color BACKGROUND_COLOR("#FF00FF");
        renderer.ClearSurface(BACKGROUND_COLOR);
        while (window.isRunning()) {
            SDL_Event event;

            while (SDL_PollEvent(&event)) {
                if (event.type == SDL_EVENT_QUIT) {
                    window.Quit();
                }
            }
        }
    } catch(const std::bad_alloc& e) {
        std::cerr<<"BAD MEMORY ALLOCATION"<<std::endl;
    } catch(...) {
        std::cerr<<"UNKNOWN ERROR"<<std::endl;
    }
    return 0;
}