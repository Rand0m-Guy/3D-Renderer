#ifndef RENDERER_H
#define RENDERER_H

#include "../../ui/sdl_window.h"
#include "../matrix/matrix2di.h"
#include "../color/color.h"
#include "../primitives/point/point.h"
#include "../vector/vector2i.h"
#include <vector> 

class Renderer {
    private:
        SDLWindow window;
        SDL_Surface *surface;
        unsigned int w;
        unsigned int h;
        std::vector<uint32_t> surfaceData;

    public:
        Renderer(SDLWindow&);
        ~Renderer();
        void ClearSurface(Color);
        void DrawPoint(vec2i_t);
        void DrawNewSurface();
};

#endif // RENDERER_H