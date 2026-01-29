#include "renderer.h"
#include <SDL3/SDL_surface.h>
#include <iostream>

Renderer::Renderer(SDLWindow& win) :    window(win),
                                        surface(SDL_GetWindowSurface(window.getWindow())),
                                        w(surface->w),
                                        h(surface->h)
{
    surfaceData.resize(w * h);
}

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

    std::fill(surfaceData.begin(), surfaceData.end(), c);

    SDL_UnlockSurface(surface);
    
    if(!SDL_UpdateWindowSurface(window.getWindow())) {
        std::cerr<<"Surface couldn't be updated"<<std::endl;
    }
}

void Renderer::DrawNewSurface() {
    SDL_Surface* newSurface = SDL_CreateSurfaceFrom(w, h, surface->format, surfaceData.data(), surface->pitch);
    
    if(!SDL_BlitSurface(newSurface, NULL, surface, NULL)) {
        std::cout<<SDL_GetError()<<std::endl;
        std::cerr<<"Surface couldn't be blit"<<std::endl;
    }

    SDL_DestroySurface(newSurface);
    
    if(!SDL_UpdateWindowSurface(window.getWindow())) {
        std::cerr<<"Surface couldn't be updated"<<std::endl;
    }
}

void Renderer::SetPointInfo(vec2i_t position) {
    surfaceData[(position.y * w + position.x) % (w * h)] = Color(ColorModel::RGB, 255, 255, 255);
}