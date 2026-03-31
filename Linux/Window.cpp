#include "Window.hpp"

Window::Window()
{
    window = nullptr;
}

Window::~Window()
{
    SDL_DestroyWindow(window);
    window = nullptr;   
}

bool Window::init()
{
    window = SDL_CreateWindow("Hello GDV4001",   // Window title
                        SDL_WINDOWPOS_UNDEFINED, // X position
                        SDL_WINDOWPOS_UNDEFINED, // Y position
                        WINDOW_WIDTH,            // width
                        WINDOW_HEIGHT,           // height               
                        SDL_WINDOW_SHOWN);       // Window flags
    
    if(window == nullptr)
        return false;
    else   
        return true;
}

SDL_Window *Window::getWindow()
{
    return window;
}
