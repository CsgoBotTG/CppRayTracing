#pragma once
#include <SFML/Graphics.hpp>
#include <math.h>
class Player
{
private:
    float x;
    float y;
    float angle;
    float speed;
public:
    Player(float _x, float _y, float _angle, float _speed);
    void movement();
    float get_angle();
    float* get_pos();
};