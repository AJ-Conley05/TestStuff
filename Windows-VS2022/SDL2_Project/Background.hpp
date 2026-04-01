#ifndef BACKGROUND_HPP
#define BACKGROUND_HPP

#include "GameObject.hpp"

class Background : public GameObject {

public:
    Background();
    ~Background();

	void update();

	void setSpeed(float speed);
	float getSpeed();

private:
    float speed;
};

#endif