#include "Background.hpp"
#include "PhysicsComponent.hpp"
#include "Vector3f.hpp"

Background::Background() : GameObject()
{
	speed = 25.0f;
}

Background::~Background()
{
}

void Background::update()
{
    float horizontal = -1.0f;
    float vertical = 0.0f;

    // std::cout << "Horizontal:" << horizontal << std::endl;
    // std::cout << "Vertical:" << vertical << std::endl;

    std::shared_ptr<Vector3f> velocity = physicsComponent->getVelocity();

    velocity->setX(horizontal);
    velocity->setY(vertical);

    // normalise or diagonals are faster. 

    // scale by speed.
    velocity->scale(speed);

    // No need to do a set - accessing the velocity directly :-P
}

void Background::setSpeed(float speed)
{
    this->speed = speed;
}

float Background::getSpeed()
{
    return speed;
}