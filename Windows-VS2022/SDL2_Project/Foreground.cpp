#include "Foreground.hpp"
#include "PhysicsComponent.hpp"
#include "Vector3f.hpp"

Foreground::Foreground() : GameObject()
{
	speed = 80.0f;
}

Foreground::~Foreground()
{
}

void Foreground::update()
{
	float horizontal = -1.0f;
	float vertical = 0.0f;

	std::shared_ptr<Vector3f> velocity = physicsComponent->getVelocity();

	velocity->setX(horizontal);
	velocity->setY(vertical);

	velocity->scale(speed);
}

void Foreground::setSpeed(float speed)
{
	this->speed = speed;
}

float Foreground::getSpeed()
{
	return speed;
}