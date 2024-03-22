#include <SFML/Graphics.hpp>
#include <math.h>

#include "player.h"

Player::Player(float _x, float _y, float _angle, float _speed) : x(_x), y(_y), angle(_angle), speed(_speed) {}

void Player::movement()
{
    float sin_a = sin(angle);
    float cos_a = cos(angle);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        x += speed * cos_a;
        y += speed * sin_a;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        x += -speed * cos_a;
        y += -speed * sin_a;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        x += speed * sin_a;
        y += -speed * cos_a;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        x += -speed * sin_a;
        y += speed * cos_a;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        angle -= 0.02;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        angle += 0.02;
    }
}

float Player::get_angle()
{
    return angle;
}

float* Player::get_pos()
{
    float position[] = { x, y };
    return position;
}