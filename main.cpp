#include "ui/SDLWindow.h"
#include <iostream>

int main(int argc, char* argv[]) {
    
    try {
        int width = 640;
        int height = 480;
        SDLWindow window(width, height);

        while (window.isRunning()) {
            SDL_Event event;

            while (SDL_PollEvent(&event)) {
                if (event.type == SDL_EVENT_QUIT) {
                    window.Quit();
                }
            }
        }
    } catch(const std::bad_alloc& e) {
        std::cout<<"[ERR] BAD MEMORY ALLOCATION\n";
    }
    return 0;
}