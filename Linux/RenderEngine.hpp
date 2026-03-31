#ifndef RENDERENGINE_HPP
#define RENDERENGINE_HPP

#include <vector>
#include <memory>

class Sprite;
class Renderer;

class RenderEngine {

public:
    RenderEngine();
    ~RenderEngine();

    void init(int maxObjects,  std::shared_ptr<Renderer> renderer);


    void addSprite(std::shared_ptr<Sprite> sprite);
    bool removeSprite(std::shared_ptr<Sprite> sprite);

    void render();
private:
    int maxObjects;
    std::vector<std::shared_ptr<Sprite>> sprites;
    std::shared_ptr<Renderer> renderer;

    
};

#endif