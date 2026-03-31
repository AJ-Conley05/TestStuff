#ifndef TRANSFORM_HPP
#define TRANSFORM_HPP

#include <memory>

class Vector3f;

class Transform {

public:
    Transform();
    ~Transform();

    void setPosition(std::shared_ptr<Vector3f> newPosition);    
    std::shared_ptr<Vector3f> getPosition();

    void setScale(std::shared_ptr<Vector3f> newScale);
    std::shared_ptr<Vector3f> getScale();

    void setAngle(float newAngle);
    float getAngle();

private:
   std::shared_ptr<Vector3f> position;
   std::shared_ptr<Vector3f> scale;
   float angle;
};

#endif