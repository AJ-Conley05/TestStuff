#include "PhysicsEngine.hpp"

#include "PhysicsComponent.hpp"
#include "GameObject.hpp"
#include "Transform.hpp"
#include "Vector3f.hpp"

PhysicsEngine::PhysicsEngine()
{
    maxObjects = 0;
}

PhysicsEngine::~PhysicsEngine()
{
    std::vector<std::shared_ptr<PhysicsComponent>>::iterator itt;
    for(itt = bodies.begin(); itt != bodies.end(); ++itt)
    {
        (*itt).reset(); // call reset on the shared pointer!
    }
    
    bodies.clear();
}

void PhysicsEngine::init(int maxObjects)
{
    bodies.resize(maxObjects);
}

void PhysicsEngine::addPhysicsComponent(std::shared_ptr<PhysicsComponent> body)
{
    bodies.push_back(body);
}

bool PhysicsEngine::removePhysicsComponent(std::shared_ptr<PhysicsComponent> body)
{
    bool deleted = false;
    std::vector<std::shared_ptr<PhysicsComponent>>::iterator itt;
    for(itt = bodies.begin(); itt != bodies.end(); ++itt)
    {
        std::shared_ptr<PhysicsComponent> temp = *itt;
        if(temp == body)
        {
            bodies.erase(itt);
            // itt - now invalid as we've altered the vector!
            deleted = true;
            break;

            /* To erase all matching*/
            //itt = sprites.erase(itt);
        }
    }

    return deleted;
}

void PhysicsEngine::update(float deltaTime)
{
    std::shared_ptr<PhysicsComponent> body;
    std::shared_ptr<GameObject> gameObject;
    std::shared_ptr<Transform> transform;
    std::shared_ptr<Vector3f> position;
    std::shared_ptr<Vector3f> velocity;

    std::vector<std::shared_ptr<PhysicsComponent>>::iterator itt;

    for(itt = bodies.begin(); itt != bodies.end(); ++itt)
    {
        body = *itt;

        if(body == nullptr)
            continue;

        gameObject = body->getGameObject();
        transform = gameObject->getTransform();
        position = transform->getPosition();
        velocity = body->getVelocity();

        Vector3f movement(*velocity);
        movement.scale(deltaTime);

        position->add(movement);
    }
}
