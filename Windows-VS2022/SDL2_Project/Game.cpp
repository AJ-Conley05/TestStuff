#include "Game.hpp"
#include "SDL2_Common.h"

#include "Window.hpp"
#include "Renderer.hpp"

#include "Timer.hpp"
#include "InputManager.hpp"

#include "RenderEngine.hpp"
#include "PhysicsEngine.hpp"

#include "Sprite.hpp"
#include "PhysicsComponent.hpp"
#include "Transform.hpp"
#include "Texture.hpp"
#include "Vector3f.hpp"

#include "GameObject.hpp"
#include "Background.hpp"
#include "Player.hpp"

#include <iostream>

Game::Game()
{
    window = nullptr;
    renderer = nullptr;
    physicsEngine = nullptr;
    renderEngine = nullptr;
    inputManager = nullptr;

    L1background1 = nullptr;
    player = nullptr;
}

Game::~Game()
{
    window.reset();
    window = nullptr;

    renderer.reset();
    renderer = nullptr;

    renderEngine.reset();
    renderEngine = nullptr;

    physicsEngine.reset();
    physicsEngine = nullptr;

    L1background1.reset();
    L1background1 = nullptr;

    player.reset();
    player = nullptr;

    //Shutdown SDL - clear up resources etc. 
    SDL_Quit();
}

void Game::init()
{
    // SDL allows us to choose which SDL components are  
    // going to be initialised. 
    // Lets go for everything for now!
    SDL_Init(SDL_INIT_EVERYTHING);

    window = std::shared_ptr<Window>(new Window());
    window->init();

    renderer = std::shared_ptr<Renderer>(new Renderer());
    renderer->init(window->getWindow());

    renderEngine = std::shared_ptr<RenderEngine>(new RenderEngine());
    renderEngine->init(MAX_GAME_OBJECTS, renderer);

    timer = Timer::instance();
    inputManager = InputManager::instance();

    physicsEngine = std::shared_ptr<PhysicsEngine>(new PhysicsEngine());
    physicsEngine->init(MAX_GAME_OBJECTS);

    createLevelBackgrounds();
    createPlayer();
}

void Game::setupGameState()
{

}

void Game::runGameLoop()
{
    // for last_time. 
    timer->update();
    inputManager->update();

    // Game loop
    while(!quit) // while quit is not true
    { 
        // update systems
        timer->update();

       
        runGameLoopOnce();
    }
}

void Game::runGameLoopOnce()
{
    float deltaTime = timer->getDeltaTime();

    // process inputs
    inputManager->update();
    quit = inputManager->isWindowClosedEvent();

    // update game state
    update(deltaTime);

    // draw
    draw();

}

void Game::draw()
{
    // Draw ...

    // 1. Clear the screen
    renderer->clear();

    // 2. Draw the scene
    renderEngine->render();

    // 3. Present the current frame to the screen
    renderer->present();
}

void Game::update(float deltaTime)
{
   physicsEngine->update(deltaTime);

   // Update game objects?
   player->update();
   L1background1->update();
   L1background2->update();
   

   //background loop when goes off screen.

   if (L1background1->getTransform()->getPosition()->getX() < -1600.0f)
   {
       L1background1->getTransform()->setPosition(std::shared_ptr<Vector3f>(new Vector3f(1600.0f, 0.0f, 0.0f)));
   }

   if (L1background2->getTransform()->getPosition()->getX() < -1600.0f)
   {
       L1background2->getTransform()->setPosition(std::shared_ptr<Vector3f>(new Vector3f(1600.0f, 0.0f, 0.0f)));
   }

}

void Game::createPlayer()
{
    player = std::shared_ptr<Player>(new Player());

    // Sprite
    std::shared_ptr<Sprite> playerSprite = std::shared_ptr<Sprite>(new Sprite());

    // Texture
    std::shared_ptr<Texture> playerTexture = std::shared_ptr<Texture>(new Texture());
    
    // This mess loads a texture .. make this better. 
    SDL_Surface* temp = IMG_Load("assets/images/claude_test.png");

    playerTexture->setTexture(SDL_CreateTextureFromSurface(renderer->getRenderer(), temp));

    SDL_FreeSurface(temp);
    temp = nullptr;

    SDL_Rect source;
    source.x = 0;
    source.y = 0;
    
    SDL_QueryTexture(playerTexture->getTexture(), NULL, NULL, &source.w, &source.h);
    playerTexture->setSourceRectangle(source);

    playerSprite->setTexture(playerTexture);
    
    // Setup two way relationship
    player->setSprite(playerSprite);
    playerSprite->setGameObject(player);

    // Add to engine
    renderEngine->addSprite(playerSprite);

    // Transform
    std::shared_ptr<Transform> playerTransform = std::shared_ptr<Transform>(new Transform());
    playerTransform->setAngle(0.0f);
    playerTransform->setPosition(std::shared_ptr<Vector3f>(new Vector3f(100.0f,100.0f,0.0f)));  

    playerTransform->setScale(std::shared_ptr<Vector3f>(new Vector3f(0.25f,0.25f,0.0f))); 

    player->setTransform(playerTransform);

    // Physics
    std::shared_ptr<PhysicsComponent> physics = std::shared_ptr<PhysicsComponent>(new PhysicsComponent());
    physics->setVelocity(std::shared_ptr<Vector3f>(new Vector3f(1.0f,1.0f,0.0f)));
    
    // setup two way relationship
    physics->setGameObject(player);
    player->setPhysicsComponent(physics);

    // Add to Engine
    physicsEngine->addPhysicsComponent(physics);
}

void Game::createLevelBackgrounds()
{
	createL1Background1();
	createL1Background2();
}

void Game::createL1Background1()
{
    L1background1 = std::shared_ptr<Background>(new Background());

    // Sprite
    std::shared_ptr<Sprite> backgroundSprite = std::shared_ptr<Sprite>(new Sprite());

    // Texture
    std::shared_ptr<Texture> backgroundTexture = std::shared_ptr<Texture>(new Texture());
    
    // This mess loads a texture .. make this better. 
    SDL_Surface* temp = IMG_Load("assets/images/Level_one_bg_part_one.png");

    backgroundTexture->setTexture(SDL_CreateTextureFromSurface(renderer->getRenderer(), temp));

    SDL_FreeSurface(temp);
    temp = nullptr;

    SDL_Rect source;
    source.x = 0;
    source.y = 0;
    
    SDL_QueryTexture(backgroundTexture->getTexture(), NULL, NULL, &source.w, &source.h);
    backgroundTexture->setSourceRectangle(source);

    backgroundSprite->setTexture(backgroundTexture);

    // Setup two way relationship
    backgroundSprite->setGameObject(L1background1);
    L1background1->setSprite(backgroundSprite);

    // Add to engine
    renderEngine->addSprite(backgroundSprite);

    // Transform
    std::shared_ptr<Transform> backgroundTransform = std::shared_ptr<Transform>(new Transform());
    backgroundTransform->setAngle(0.0f);
    backgroundTransform->setPosition(std::shared_ptr<Vector3f>(new Vector3f(0.0f,0.0f,0.0f)));  
    
    float bgScaleX = Window::WINDOW_WIDTH/(float)source.w;
    float bgScaleY = Window::WINDOW_HEIGHT/(float)source.h;

    backgroundTransform->setScale(std::shared_ptr<Vector3f>(new Vector3f(1.0f,bgScaleY,0.0f))); 

    L1background1->setTransform(backgroundTransform);

    // Physics
    std::shared_ptr<PhysicsComponent> backgroundPhysics = std::shared_ptr<PhysicsComponent>(new PhysicsComponent());
    backgroundPhysics->setVelocity(std::shared_ptr<Vector3f>(new Vector3f(1.0f, 1.0f, 0.0f)));

    // setup two way relationship
    backgroundPhysics->setGameObject(L1background1);
    L1background1->setPhysicsComponent(backgroundPhysics);

    // Add to Engine
    physicsEngine->addPhysicsComponent(backgroundPhysics);
}

void Game::createL1Background2()
{
    L1background2 = std::shared_ptr<Background>(new Background());

    // Sprite
    std::shared_ptr<Sprite> backgroundSprite = std::shared_ptr<Sprite>(new Sprite());

    // Texture
    std::shared_ptr<Texture> backgroundTexture = std::shared_ptr<Texture>(new Texture());

    // This mess loads a texture .. make this better. 
    SDL_Surface* temp = IMG_Load("assets/images/Level_one_bg_part_two.PNG");

    backgroundTexture->setTexture(SDL_CreateTextureFromSurface(renderer->getRenderer(), temp));

    SDL_FreeSurface(temp);
    temp = nullptr;

    SDL_Rect source;
    source.x = 0;
    source.y = 0;

    SDL_QueryTexture(backgroundTexture->getTexture(), NULL, NULL, &source.w, &source.h);
    backgroundTexture->setSourceRectangle(source);

    backgroundSprite->setTexture(backgroundTexture);

    // Setup two way relationship
    backgroundSprite->setGameObject(L1background2);
    L1background2->setSprite(backgroundSprite);

    // Add to engine
    renderEngine->addSprite(backgroundSprite);

    // Transform
    std::shared_ptr<Transform> backgroundTransform = std::shared_ptr<Transform>(new Transform());
    backgroundTransform->setAngle(0.0f);
    backgroundTransform->setPosition(std::shared_ptr<Vector3f>(new Vector3f(1600.0f, 0.0f, 0.0f)));

    float bgScaleX = Window::WINDOW_WIDTH / (float)source.w;
    float bgScaleY = Window::WINDOW_HEIGHT / (float)source.h;

    backgroundTransform->setScale(std::shared_ptr<Vector3f>(new Vector3f(1.0f, bgScaleY, 0.0f)));

    L1background2->setTransform(backgroundTransform);

    // Physics
    std::shared_ptr<PhysicsComponent> backgroundPhysics = std::shared_ptr<PhysicsComponent>(new PhysicsComponent());
    backgroundPhysics->setVelocity(std::shared_ptr<Vector3f>(new Vector3f(1.0f, 1.0f, 0.0f)));

    // setup two way relationship
    backgroundPhysics->setGameObject(L1background2);
    L1background2->setPhysicsComponent(backgroundPhysics);

    // Add to Engine
    physicsEngine->addPhysicsComponent(backgroundPhysics);
}
