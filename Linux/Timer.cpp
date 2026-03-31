#include "Timer.hpp"
#include "SDL2_Common.h"
#include "InputManager.hpp"

Timer::Timer()
{
	deltaTime = 0.0f;
}

void Timer::init()
{
	// Initialise previous time index. 
	prevTimeIndex = SDL_GetTicks();
}

void Timer::update()
{
    // Calculate time elapsed
    // Better approaches to this exist - https://gafferongames.com/post/fix_your_timestep/

    currentTimeIndex = SDL_GetTicks();
    timeDelta = currentTimeIndex - prevTimeIndex; //time in milliseconds
    deltaTime = timeDelta * 0.001f; //time in seconds

    // Store current time index into prevTimeIndex for next frame
    prevTimeIndex = currentTimeIndex;
}

float Timer::getDeltaTime()
{
    return deltaTime;
}