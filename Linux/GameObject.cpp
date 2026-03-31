#include "GameObject.hpp"

#include "Transform.hpp"
#include "Sprite.hpp"

GameObject::GameObject()
{
    sprite = nullptr;
    transform = nullptr;
}

GameObject::~GameObject()
{
    sprite.reset();
    sprite = nullptr;

    transform.reset();
    transform = nullptr;
}

void GameObject::setSprite(std::shared_ptr<Sprite> newSprite)
{
    sprite = newSprite;
}

std::shared_ptr<Sprite> GameObject::getSprite()
{
    return sprite;
}

void GameObject::setTransform(std::shared_ptr<Transform> newTransform)
{
    transform = newTransform;
}

std::shared_ptr<Transform> GameObject::getTransform()
{
    return transform;
}

void GameObject::setPhysicsComponent(std::shared_ptr<PhysicsComponent> newPhysicsComponent)
{
    physicsComponent = newPhysicsComponent;
}

std::shared_ptr<PhysicsComponent> GameObject::getPhysicsComponent()
{
    return physicsComponent;
}
