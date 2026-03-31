#include "PhysicsComponent.hpp"

#include "GameObject.hpp"
#include "Transform.hpp"
#include "Vector3f.hpp"

PhysicsComponent::PhysicsComponent()
{
    gameObject = nullptr;
    velocity = nullptr;
}

PhysicsComponent::PhysicsComponent(std::shared_ptr<Vector3f> newVelocity, std::shared_ptr<GameObject> newGameObject)
{
    gameObject = newGameObject;
    velocity = newVelocity;
}

PhysicsComponent::~PhysicsComponent()
{
    gameObject.reset();
    gameObject = nullptr;
    velocity.reset();
    velocity = nullptr;
}

void PhysicsComponent::setGameObject(std::shared_ptr<GameObject> newGameObject)
{
    gameObject = newGameObject;
}

std::shared_ptr<GameObject> PhysicsComponent::getGameObject()
{
    return gameObject;
}

void PhysicsComponent::setVelocity(std::shared_ptr<Vector3f> newVelocity)
{
    velocity = newVelocity;
}

std::shared_ptr<Vector3f> PhysicsComponent::getVelocity()
{
    return velocity;
}



