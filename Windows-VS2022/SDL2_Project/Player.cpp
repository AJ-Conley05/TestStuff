#include "Player.hpp"
#include "InputManager.hpp"
#include "PhysicsComponent.hpp"
#include "Vector3f.hpp"

#include <iostream>

Player::Player() : GameObject()
{
    speed = 250.0f;
}

Player::~Player()
{
}

void Player::update()
{
    float horizontal = InputManager::instance()->getHorizontalInput();
    float vertical = InputManager::instance()->getVerticalInput();

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

void Player::setSpeed(float speed)
{
    this->speed = speed;
}

float Player::getSpeed()
{
    return speed;
}
