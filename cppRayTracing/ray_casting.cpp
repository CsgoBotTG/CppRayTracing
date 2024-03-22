#include <SFML/Graphics.hpp>
#include <utility>
#include <set>

#include "ray_casting.h"

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
    float HEIGHT,
    float SCALE,
    float DELTA_ANGLE
)
{
    float cur_angle = player_angle - HALF_FOV;
    float xo = player_pos[0];
    float yo = player_pos[1];

    for (int ray = 0; ray < NUM_RAYS; ray++)
    {
        float sin_a = (float)sin(cur_angle);
        float cos_a = (float)cos(cur_angle);

        for (int depth = 0; depth < MAX_DEPTH; depth++)
        {
            float x = xo + depth * cos_a;
            float y = yo + depth * sin_a;

            bool found = false;
            std::pair<int, int> to_find = std::make_pair((int)x / TILE * TILE, (int)y / TILE * TILE);
            for (std::pair<int, int> helper : world_map)
            {
                if (helper == to_find)
                {
                    found = true;
                    break;
                }
            }

            if (found)
            {
                depth *= (float)cos(player_angle - cur_angle);

                float proj_height = std::min(PROJ_COEFF / (depth + 0.0001f), HEIGHT);
                int c = 255 / (1 + depth * depth * 0.0001f);
                sf::Color color(c / 2, c, c /3);

                sf::RectangleShape rect;
                rect.setFillColor(color);
                rect.setPosition(sf::Vector2f(ray * SCALE, (int)((HEIGHT - proj_height) / 2)));
                rect.setSize(sf::Vector2f(SCALE, proj_height));

                (*window).draw(rect);
                break;
            }
        }

        cur_angle += DELTA_ANGLE;
    }
}