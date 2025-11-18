#include "sdl_window.h"
#include <new>
#include <cstdlib>

SDLWindow::SDLWindow(int width, int height) {
    SDL_Init(SDL_INIT_VIDEO); // Initializes SDL3

    this->windowWidth = width;
    this->windowHeight = height;

    SDL_PropertiesID props = SDL_CreateProperties();
    SDL_SetNumberProperty(props, SDL_PROP_WINDOW_CREATE_WIN32_PIXEL_FORMAT_HWND_POINTER, SDL_PIXELFORMAT_RGBA32);
    SDL_SetNumberProperty(props, SDL_PROP_WINDOW_CREATE_WIDTH_NUMBER, this->windowWidth);
    SDL_SetNumberProperty(props, SDL_PROP_WINDOW_CREATE_HEIGHT_NUMBER, this->windowHeight);
    SDL_SetStringProperty(props, SDL_PROP_WINDOW_CREATE_TITLE_STRING, "3D Renderer");

    window = SDL_CreateWindowWithProperties(props);

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