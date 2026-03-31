#include "Texture.hpp"

Texture::Texture()
{
    source.x = 0;
    source.y = 0;
    source.w = 0;
    source.h = 0;

    texture = nullptr;

    angleOffset = 0.0f;
}

Texture::~Texture()
{
    SDL_DestroyTexture(texture);
}


void Texture::setSourceRectangle(SDL_Rect newSourceRectangle)
{
    source = newSourceRectangle;
}

SDL_Rect Texture::getSourceRectangle()
{
    return source;
}


void Texture::setTexture(SDL_Texture* newTexture)
{
    texture = newTexture;
}

SDL_Texture* Texture::getTexture()
{
    return texture;
}


void Texture::setAngleOffset(float newAngle)
{
    angleOffset = newAngle;
}

float Texture::getAngleOffset()
{
    return angleOffset;
}
