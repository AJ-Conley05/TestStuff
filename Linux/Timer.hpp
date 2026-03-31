#ifndef TIMER_HPP
#define TIMER_HPP

#include <memory>

class Timer
{
private:
	// Singlton - private constructor!
	Timer();
	void init();
	float deltaTime;

	// Timing variables
	unsigned int currentTimeIndex;
	unsigned int prevTimeIndex;
	unsigned int timeDelta;

public:
	/* Alternative Singlton pattern using shared_ptr */
	static std::shared_ptr<Timer> instance()
	{
		static std::shared_ptr<Timer> timer(new Timer());
		return timer;
	}

	void update();
	float getDeltaTime();
};

#endif

