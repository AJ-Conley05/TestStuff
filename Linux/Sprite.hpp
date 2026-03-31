#ifndef SPRITE_HPP
#define SPRITE_HPP

#include <memory>

class GameObject;
class Texture;

class Sprite {

public:
    Sprite();
    ~Sprite();

    void setGameObject(std::shared_ptr<GameObject> newGameObject);
    std::shared_ptr<GameObject> getGameObject();

    void setTexture(std::shared_ptr<Texture> newTexture);
    std::shared_ptr<Texture> getTexture();

private:
    std::shared_ptr<GameObject> gameObject;
    std::shared_ptr<Texture> texture;
};

#endif