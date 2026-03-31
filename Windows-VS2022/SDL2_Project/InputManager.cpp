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
    if (keyStates[SDL_SCANCODE_D])
        return 0.5f;
    else
    {
        if (keyStates[SDL_SCANCODE_A])
            return -0.5f;
        else
            return 0.0f;
    }
}

float InputManager::getVerticalInput()
{
    if (keyStates[SDL_SCANCODE_W])
        return -0.5f;
    else
    {
        if (keyStates[SDL_SCANCODE_S])
            return 0.5f;
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

    if (keyStates[SDL_SCANCODE_ESCAPE])
		quit = true;
}