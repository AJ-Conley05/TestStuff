#ifndef PLAYER_HPP
#define PLAYER_HPP


#include "GameObject.hpp"

class Player : public GameObject {

public:
    Player();
    ~Player();

    void update();

    void setSpeed(float speed);
    float getSpeed();
private:
    float speed;
};

#endif