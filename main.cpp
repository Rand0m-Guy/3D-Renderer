#include "ui/sdl_window.h"
#include "core/renderer/renderer.h"
#include "core/projection/perspective.h"
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
        Perspective perspective;
        vec3_t point = {.x = 10.0f, .y = 10.0f, .z = 10.0f};
        float idx = 0.0f;

        while (window.isRunning()) {
            SDL_Event event;
            
            point = {.x = idx, .y = idx, .z = 1.0f};
            idx += .05f;

            renderer.SetPointInfo(perspective.project(point), Color(ColorModel::RGB, 255, 255, 255));
            renderer.DrawNewSurface();

            renderer.SetPointInfo(perspective.project(point), BACKGROUND_COLOR);

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