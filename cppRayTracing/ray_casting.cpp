#include <SFML/Graphics.hpp>
#include <utility>
#include <set>

#include "ray_casting.h"

std::pair<int, int> mapping(float a, float b, int TILE)
{
    return std::make_pair((int)a / TILE * TILE, (int)b / TILE * TILE);
}

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
)
{
    float ox = player_pos[0];
    float oy = player_pos[1];
    std::pair<int, int> mapped = mapping(ox, oy, TILE);
    float xm = mapped.first;
    float ym = mapped.second;
    float cur_angle = player_angle - HALF_FOV;

    for (int ray = 0; ray < NUM_RAYS; ray++)
    {

        float sin_a = sin(cur_angle);
        float cos_a = cos(cur_angle);
        if (sin_a == 0.0f)
            sin_a = 0.000001f;
        if (cos_a == 0.0f)
            cos_a = 0.000001f;

        // define
        float x, dx, y, dy, depth_v, depth_h;

        // verticals
        if (cos_a >= 0.0f)
        {
            x = xm + TILE;
            dx = 1.f;
        }
        else
        {
            x = xm;
            dx = -1.f;
        }

        for (int i = 0; i < WIDTH; i += TILE)
        {
            depth_v = (x - ox) / cos_a;
            y = oy + depth_v * sin_a;
            
            bool found = false;
            mapped = mapping(x + dx, y, TILE);
            for (auto helper : world_map)
            {
                if (helper == mapped)
                {
                    found = true;
                    break;
                }
            }

            if (found)
                break;
            
            x += dx * TILE;
        }


        // horizontals
        if (sin_a >= 0.0f)
        {
            y = ym + TILE;
            dy = 1;
        }
        else
        {
            y = ym;
            dy = -1;
        }

        for (int i = 0; i < HEIGHT; i += TILE)
        {
            depth_h = (y - oy) / sin_a;
            x = ox + depth_h * cos_a;

            bool found = false;
            mapped = mapping(x, y + dy, TILE);
            for (auto helper : world_map)
            {
                if (helper == mapped)
                {
                    found = true;
                    break;
                }
            }

            if (found)
                break;

            y += dy * TILE;
        }

        // projection
        float depth = std::min(depth_h, depth_v);
        depth *= cos(player_angle - cur_angle);
        float proj_height = PROJ_COEFF / depth;
        int c = 255 / (1 + depth * depth * 0.00002f);
        sf::Color color(c, c / 2, c / 3);

        sf::RectangleShape rect;
        rect.setFillColor(color);
        rect.setPosition(sf::Vector2f(ray * SCALE, (HEIGHT - proj_height) / 2));
        rect.setSize(sf::Vector2f(SCALE, proj_height));

        (*window).draw(rect);

        cur_angle += DELTA_ANGLE;
    }
}