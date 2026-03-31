#include "Sprite.hpp"

#include "GameObject.hpp"
#include "Texture.hpp"

Sprite::Sprite()
{
    gameObject = nullptr;
    texture = nullptr;
}

Sprite::~Sprite()
{
    gameObject.reset();
    gameObject = nullptr;
    texture.reset();
    texture = nullptr;
}

void Sprite::setGameObject(std::shared_ptr<GameObject> newGameObject)
{
    gameObject = newGameObject;
}

std::shared_ptr<GameObject> Sprite::getGameObject()
{
    return gameObject;
}

void Sprite::setTexture(std::shared_ptr<Texture> newTexture)
{
    texture = newTexture;
}

std::shared_ptr<Texture> Sprite::getTexture()
{
    return texture;
}

