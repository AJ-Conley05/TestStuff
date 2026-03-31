#ifndef PHYSICS_OBJECT_HPP
#define PHYSICS_OBJECT_HPP

#include <memory>

class GameObject;
class Vector3f;

class PhysicsComponent {

public:
    PhysicsComponent();
    PhysicsComponent(std::shared_ptr<Vector3f> newVelocity, std::shared_ptr<GameObject> newGameObject);
    ~PhysicsComponent();

    void setGameObject(std::shared_ptr<GameObject> newGameObject);
    std::shared_ptr<GameObject> getGameObject();

    void setVelocity(std::shared_ptr<Vector3f> newVelocity);
    std::shared_ptr<Vector3f> getVelocity();


private:
    std::shared_ptr<GameObject> gameObject;
    std::shared_ptr<Vector3f> velocity;

};

#endif