#include "RenderEngine.hpp"

#include "Sprite.hpp"
#include "Renderer.hpp"
#include "Texture.hpp"
#include "GameObject.hpp"
#include "Transform.hpp"
#include "Vector3f.hpp"

RenderEngine::RenderEngine()
{
    maxObjects = 0;
}

RenderEngine::~RenderEngine()
{
    std::vector<std::shared_ptr<Sprite>>::iterator itt;
    for(itt = sprites.begin(); itt != sprites.end(); ++itt)
    {
        (*itt).reset(); // call reset on the shared pointer!
    }
    
    sprites.clear();
}

void RenderEngine::init(int maxObjects, std::shared_ptr<Renderer> renderer)
{
    sprites.resize(maxObjects);

    this->renderer = renderer;
}

void RenderEngine::addSprite(std::shared_ptr<Sprite> sprite)
{
    sprites.push_back(sprite);
}

bool RenderEngine::removeSprite(std::shared_ptr<Sprite> sprite)
{
    bool deleted = false;
    std::vector<std::shared_ptr<Sprite>>::iterator itt;
    for(itt = sprites.begin(); itt != sprites.end(); ++itt)
    {
        std::shared_ptr<Sprite> temp = *itt;
        if(temp == sprite)
        {
            sprites.erase(itt);
            // itt - now invalid as we've altered the vector!
            deleted = true;
            break;

            /* To erase all matching*/
            //itt = sprites.erase(itt);
        }
    }

    return deleted;
}

void RenderEngine::render()
{
    // slow?
    SDL_Renderer* gameRenderer = renderer->getRenderer();
    SDL_Rect destination;
    SDL_Rect source;
    SDL_Texture* tex;

    std::shared_ptr<Sprite> sprite;
    std::shared_ptr<Texture> texture;
    std::shared_ptr<Transform> transform;
    std::shared_ptr<Vector3f> scale;
    std::shared_ptr<Vector3f> position;
    float angle;

    std::vector<std::shared_ptr<Sprite>>::iterator itt;

    for(itt = sprites.begin(); itt != sprites.end(); ++itt)
    {
        sprite = *itt;

        if(sprite == nullptr)
            continue;

        texture = sprite->getTexture();
        source = texture->getSourceRectangle();
        tex = texture->getTexture();

        transform = sprite->getGameObject()->getTransform();
        scale = transform->getScale();
        position = transform->getPosition();

        destination.x = position->getX();
        destination.y = position->getY();
        destination.w = source.w * scale->getX();
        destination.h = source.h * scale->getY();

        angle = transform->getAngle(); // angle of the game object.
        angle += texture->getAngleOffset(); // offset of image in the texture. 


        SDL_RenderCopyEx(gameRenderer, tex, &source, &destination, angle, NULL, SDL_FLIP_NONE);
    }
}