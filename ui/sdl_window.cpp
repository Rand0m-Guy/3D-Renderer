#include "sdl_window.h"
#include <new>
#include <cstdlib>

SDLWindow::SDLWindow(int width, int height) {
    SDL_Init(SDL_INIT_VIDEO); // Initializes SDL3

    this->windowWidth = width;
    this->windowHeight = height;
    window = SDL_CreateWindow(
        "3D Renderer",          // Window title        
        this->windowWidth,
        this->windowHeight,
        SDL_WINDOW_OPENGL       // Flags
    );

    if (window == NULL) { // If window was not created
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Could not create window: %s\n", SDL_GetError());
        throw std::bad_alloc();
    }

    this->running = true;
}

SDLWindow::~SDLWindow() {
    SDL_DestroyWindow(this->window);
    SDL_Quit();
}

bool SDLWindow::isRunning() {
    return this->running;
}

void SDLWindow::Quit() {
    this->running = false;
}

SDL_Window* SDLWindow::getWindow() {
    return this->window;
}