#ifndef INPUT_MANAGER_HPP
#define INPUT_MANAGER_HPP

#include <memory>
#include "SDL2_Common.h"

class InputManager
{
private:
	// Singleton - private constructor!
	InputManager();
	void init();

	SDL_Event event;
	bool quit;
	const Uint8* keyStates;

public:
	/* Alternative Singleton pattern using shared_ptr */
	static std::shared_ptr<InputManager> instance()
	{
		static std::shared_ptr<InputManager> inputManager(new InputManager());
		inputManager->init();
		return inputManager;
	}
	~InputManager();

	void update();
	bool isWindowClosedEvent();
	float getHorizontalInput();
	float getVerticalInput();

};
#endif

