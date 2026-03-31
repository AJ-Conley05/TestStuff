#ifndef GAME_HPP
#define GAME_HPP

#include "SDL2_Common.h"
#include <memory>

class Window;
class Renderer;
class PhysicsEngine;
class Timer;
class InputManager;
class RenderEngine;
class Background;
class Player;

class Game {

public:
    Game();
    ~Game();

    void init();
    void setupGameState();
    void runGameLoop();

    static const int MAX_GAME_OBJECTS = 32;

protected:
    std::shared_ptr <Window> window;
    std::shared_ptr <Renderer> renderer;
    std::shared_ptr<Timer> timer;
    std::shared_ptr<InputManager> inputManager;
    std::shared_ptr<RenderEngine> renderEngine;
    std::shared_ptr<PhysicsEngine> physicsEngine;

    // Background
    std::shared_ptr<Background> background;

    //
    std::shared_ptr<Player> player;

    // Window control 
    bool quit = false;

    void runGameLoopOnce();
    void draw();
    void update(float deltaTime);

    // Temporary
    void createBackground();
    void createPlayer();
};

#endif