#include <SFML/Graphics.hpp>

#include "ray_casting.h"
#include "settings.h"
#include "player.h"
#include "map.h"

int main()
{
    // player
    Player player(HALF_WIDTH, HALF_HEIGHT, 0.0f, 2.0f);

    // world map
    std::set<std::pair<int, int>> world_map = init_world_map(TILE);

    // window init
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), TITLE, sf::Style::Close);
    window.setFramerateLimit(FPS);

    // background
    sf::RectangleShape sky;
    sky.setFillColor(sf::Color(0, 0, 255));
    sky.setPosition(sf::Vector2f(0,0));
    sky.setSize(sf::Vector2f(WIDTH, HALF_HEIGHT));

    sf::RectangleShape earth;
    earth.setFillColor(sf::Color(40, 40, 40));
    earth.setPosition(sf::Vector2f(0, HALF_HEIGHT));
    earth.setSize(sf::Vector2f(WIDTH, HALF_HEIGHT));
    
    // game loop
    while (window.isOpen())
    {
        // event polling
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        // closing if ESCAPE is PRESSED
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            window.close();
        
        // game logic
        window.draw(sky);
        window.draw(earth);

        player.movement();
        ray_casting(
            &window,
            world_map,
            player.get_pos(),
            player.get_angle(),
            HALF_FOV,
            NUM_RAYS,
            MAX_DEPTH,
            TILE,
            PROJ_COEFF,
            HEIGHT,
            SCALE,
            DELTA_ANGLE
        );

        // display image
        window.display();
    }

    return 0;
}