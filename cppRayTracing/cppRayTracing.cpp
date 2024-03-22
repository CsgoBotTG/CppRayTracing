#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
#include <math.h>

#include "settings.h"
#include "player.h"
#include "ray_casting.h"
#include "map.h"

using namespace std;
using namespace sf;

int game_loop()
{
    // player
    Player player(HALF_WIDTH, HALF_HEIGHT, 0.0f, 2.0f);

    // world map
    set<pair<int, int>> world_map = make_world_map(text_map, TILE);

    // game
    RenderWindow window(VideoMode(WIDTH, HEIGHT), TITLE, Style::Close);
    window.setFramerateLimit(FPS);

    RectangleShape sky;
    sky.setFillColor(Color(0, 0, 255));
    sky.setPosition(Vector2f(0,0));
    sky.setSize(Vector2f(WIDTH, HALF_HEIGHT));

    RectangleShape earth;
    earth.setFillColor(Color(40, 40, 40));
    earth.setPosition(Vector2f(0, HALF_HEIGHT));
    earth.setSize(Vector2f(WIDTH, HALF_HEIGHT));

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        if (Keyboard::isKeyPressed(Keyboard::Escape))
            window.close();
        
        window.draw(sky);
        window.draw(earth);

        player.movement();
        ray_casting(
            &window,
            player.get_pos(),
            player.get_angle(),
            world_map,
            HALF_FOV,
            NUM_RAYS,
            MAX_DEPTH,
            TILE,
            PROJ_COEFF,
            HEIGHT,
            SCALE,
            DELTA_ANGLE
        );

        window.display();
    }

    return 0;
}