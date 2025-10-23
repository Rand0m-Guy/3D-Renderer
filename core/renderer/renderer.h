#ifndef RENDERER_H
#define RENDERER_H

#include "../../ui/sdl_window.h"

class Renderer {
    private:
        SDL_PropertiesID windowProperties;

    public:
        Renderer(SDLWindow&);
        // ~Renderer();
};

#endif // RENDERER_H