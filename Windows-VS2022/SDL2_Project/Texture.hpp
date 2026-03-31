#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include "SDL2_Common.h"

class Texture {

public:
    Texture();
    ~Texture();

    void setSourceRectangle(SDL_Rect newSourceRectangle);
    SDL_Rect getSourceRectangle();

    void setTexture(SDL_Texture* newTexture);
    SDL_Texture* getTexture();

    void setAngleOffset(float newAngle);
    float getAngleOffset();

private:
    SDL_Rect source;
    SDL_Texture* texture;
    float angleOffset;
};

#endif