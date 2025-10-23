#include "renderer.h"
#include <stdexcept>
#include <SDL3/SDL_properties.h>
#include <iostream>

Renderer::Renderer(SDLWindow& window) {
    this->windowProperties = window.getWindowProperties();

    if(this->windowProperties == 0) {
        throw std::runtime_error("Couldn't access SDL_Window properties");
    }

    #ifdef linux
        // Linux (X11)
        Window xwindow = SDL_GetPointerProperty(this->windowProperties, SDL_PROP_WINDOW_X11_WINDOW_NUMBER, NULL);

    #endif
}