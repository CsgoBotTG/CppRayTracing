#pragma once
#include <SFML/Graphics.hpp>
#include <utility>
#include <set>
void ray_casting(
    sf::RenderWindow* window,
    float player_pos[],
    float player_angle,
    std::set<std::pair<int, int>> world_map,
    float HALF_FOV,
    int NUM_RAYS,
    int MAX_DEPTH,
    int TILE,
    float PROJ_COEFF,
    float HEIGHT,
    float SCALE,
    float DELTA_ANGLE
);