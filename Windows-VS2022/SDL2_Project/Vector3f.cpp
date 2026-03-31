#include "Vector3f.hpp"

Vector3f::Vector3f()
{
    x = y = z = 0.0f;
}

Vector3f::Vector3f(float x, float y, float z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

Vector3f::~Vector3f()
{
}

void Vector3f::setX(float newX)
{
    x = newX;
}

void Vector3f::setY(float newY)
{
    y = newY;
}

void Vector3f::setZ(float newZ)
{
    z = newZ;
}

float Vector3f::getX()
{
    return x;
}

float Vector3f::getY()
{
    return y;
}

float Vector3f::getZ()
{
    return z;
}

void Vector3f::scale(float scalingFactor)
{
    x *= scalingFactor;
    y *= scalingFactor;
    z *= scalingFactor;
}

void Vector3f::add(Vector3f &other)
{
    x += other.getX();
    y += other.getY();
    z += other.getZ();
}
