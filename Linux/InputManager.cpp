#include "InputManager.hpp"

InputManager::InputManager()
{
    keyStates = nullptr;
    quit = false;
}

void InputManager::init()
{
    // Track Keystates array
    keyStates = SDL_GetKeyboardState(NULL);
}

InputManager::~InputManager()
{
    keyStates = nullptr;
}

bool InputManager::isWindowClosedEvent()
{
    return quit;
}

float InputManager::getHorizontalInput()
{
    if (keyStates[SDL_SCANCODE_RIGHT])
        return 1.0f;
    else
    {
        if (keyStates[SDL_SCANCODE_LEFT])
            return -1.0f;
        else
            return 0.0f;
    }
}

float InputManager::getVerticalInput()
{
    if (keyStates[SDL_SCANCODE_UP])
        return -1.0f;
    else
    {
        if (keyStates[SDL_SCANCODE_DOWN])
            return 1.0f;
        else
            return 0.0f;
    }
}

void InputManager::update()
{
    if (SDL_PollEvent(&event))  // test for events
    {
        switch (event.type)
        {
            case SDL_QUIT:
                quit = true;
            break;
        }
    }
}