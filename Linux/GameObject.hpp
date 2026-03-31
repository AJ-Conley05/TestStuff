#ifndef GAME_OBJECT_HPP
#define GAME_OBJECT_HPP

#include <memory>

class Sprite;
class Transform;
class PhysicsComponent;

class GameObject {

public:
    GameObject();
    virtual ~GameObject();

    void setSprite(std::shared_ptr<Sprite> newSprite);
    std::shared_ptr<Sprite> getSprite();

    void setTransform(std::shared_ptr<Transform> newTransform);
    std::shared_ptr<Transform> getTransform();

    void setPhysicsComponent(std::shared_ptr<PhysicsComponent> newPhysicsComponent);
    std::shared_ptr<PhysicsComponent> getPhysicsComponent();

protected:
    std::shared_ptr<Sprite> sprite;
    std::shared_ptr<Transform> transform;
    std::shared_ptr<PhysicsComponent> physicsComponent;
};

#endif