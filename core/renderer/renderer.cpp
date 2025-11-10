#include "renderer.h"
#include <SDL3/SDL_surface.h>
#include <iostream>

Renderer::Renderer(SDLWindow& win) :    window(win),
                                        surface(SDL_GetWindowSurface(win.getWindow())),
                                        surfaceBuffer(surface->w, surface->h)
{}

Renderer::~Renderer() {
    SDL_DestroySurface(this->surface);
}

void Renderer::ClearSurface(Color c) {
    if(!SDL_LockSurface(surface)) {
        std::cerr<<"Surface couldn't be locked"<<std::endl;
    }

    if(!SDL_ClearSurface(surface, c.getAsFloat_r(), c.getAsFloat_g(), c.getAsFloat_b(), c.getAsFloat_a())) {
        std::cerr<<"Surface couldn't be cleared"<<std::endl;
    }

    SDL_UnlockSurface(surface);
    
    if(!SDL_UpdateWindowSurface(window.getWindow())) {
        std::cerr<<"Surface couldn't be updated"<<std::endl;
    }
}