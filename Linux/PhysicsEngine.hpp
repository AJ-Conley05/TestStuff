#ifndef PHYSICS_ENGINE_HPP
#define PHYSICS_ENGINE_HPP

#include <vector>
#include <memory>

class PhysicsComponent;

class PhysicsEngine {

public:
    PhysicsEngine();
    ~PhysicsEngine();

    void init(int maxObjects);


    void addPhysicsComponent(std::shared_ptr<PhysicsComponent> sprite);
    bool removePhysicsComponent(std::shared_ptr<PhysicsComponent> sprite);

    void update(float dt);
private:
    int maxObjects;
    std::vector<std::shared_ptr<PhysicsComponent>> bodies;
    
};

#endif