#include "Renderer.hpp"

Renderer::Renderer()
{
    renderer = nullptr;
}

bool Renderer::init(SDL_Window* window)
{
    renderer = SDL_CreateRenderer(window, 0, 0);

    if(renderer == nullptr)
        return false;
    else 
        return true;
}

SDL_Renderer *Renderer::getRenderer()
{
    return renderer;
}

Renderer::~Renderer()
{
    SDL_DestroyRenderer(renderer);
    renderer = nullptr;
}

void Renderer::clear()
{
    // Colour provided as red, green, blue and alpha (transparency) values (ie. RGBA)
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
}

void Renderer::present()
{
    SDL_RenderPresent(renderer);
}