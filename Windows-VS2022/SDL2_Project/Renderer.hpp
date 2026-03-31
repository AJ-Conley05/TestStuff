#ifndef RENDERER_HPP
#define RENDERER_HPP

#include "SDL2_Common.h"

class Renderer {

public:
    Renderer();
    ~Renderer();

    bool init(SDL_Window* window);
    SDL_Renderer* getRenderer();
    void clear();
    void present();
    
private:
    SDL_Renderer* renderer;
};

#endif