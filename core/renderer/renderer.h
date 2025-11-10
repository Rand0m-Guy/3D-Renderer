#ifndef RENDERER_H
#define RENDERER_H

#include "../../ui/sdl_window.h"
#include "../matrix/matrix2di.h"
#include "../color/color.h"

class Renderer {
    private:
        SDLWindow window;
        SDL_Surface *surface;
        Matrix2Di surfaceBuffer;

    public:
        Renderer(SDLWindow&);
        ~Renderer();
        void ClearSurface(Color);
};

#endif // RENDERER_H