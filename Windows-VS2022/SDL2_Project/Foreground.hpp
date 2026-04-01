#ifndef FOREGROUND_HPP
#define FOREGROUND_HPP

#include "GameObject.hpp"

class Foreground : public GameObject
{
public:
	Foreground();
	~Foreground();

	void update();

	void setSpeed(float speed);
	float getSpeed();
private:
	float speed;
};

#endif