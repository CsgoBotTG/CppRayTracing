#pragma once
#include <SFML/Graphics.hpp>
#include <utility>
#include <set>
std::pair<int, int> mapping(float a, float b, int TILE);
void ray_casting(
    sf::RenderWindow* window,
    std::set<std::pair<int, int>> world_map,
    float player_pos[],
    float player_angle,
    float HALF_FOV,
    int NUM_RAYS,
    int MAX_DEPTH,
    int TILE,
    float PROJ_COEFF,
    float WIDTH,
    float HEIGHT,
    float SCALE,
    float DELTA_ANGLE
);