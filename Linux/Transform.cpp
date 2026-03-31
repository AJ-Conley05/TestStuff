#include "Transform.hpp"

Transform::Transform()
{
    position = nullptr;
    scale = nullptr;
    angle = 0.0f;
}

Transform::~Transform()
{
    position.reset();
    position = nullptr;

    scale.reset();
    scale = nullptr;
}

void Transform::setPosition(std::shared_ptr<Vector3f> newPosition)
{
    position = newPosition;
}

std::shared_ptr<Vector3f> Transform::getPosition()
{
    return position;
}

void Transform::setScale(std::shared_ptr<Vector3f> newScale)
{
    scale = newScale;
}

std::shared_ptr<Vector3f> Transform::getScale()
{
    return scale;
}

void Transform::setAngle(float newAngle)
{
    angle = newAngle;
}

float Transform::getAngle()
{
    return angle;
}
