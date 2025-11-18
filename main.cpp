#include "ui/sdl_window.h"
#include "core/renderer/renderer.h"
#include <iostream>
#include <vector>

int main(int argc, char* argv[]) {
    try {
        int width = 640;
        int height = 480;
        SDLWindow window(width, height);
        Renderer renderer(window);
        Color BACKGROUND_COLOR(ColorModel::RGB, 20, 20, 20);
        renderer.ClearSurface(BACKGROUND_COLOR);
        vec2i_t p;
        renderer.DrawPoint(p);
        renderer.DrawNewSurface();
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