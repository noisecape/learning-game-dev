#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <type_traits>


int main()
{
    // declare a bunch of consts
    const int WINDOW_WIDTH = 1280;
    const int WINDOW_HEIGHT = 720;
    const int WINDOW_FPS = 60;
    const float CIRCLE_RADIUS = 25.0f;
    float PLAYER_SPEED_X = 1.5f;
    float PLAYER_SPEED_Y = 1.5f;


    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Assignment 1");

    // set window frame rate
    window.setFramerateLimit(WINDOW_FPS);

    // create the player
    sf::CircleShape player(CIRCLE_RADIUS);
    player.setFillColor(sf::Color::Green);
    player.setPosition(WINDOW_WIDTH / 2.0f, WINDOW_HEIGHT / 2.0f);
    player.setOrigin(CIRCLE_RADIUS, CIRCLE_RADIUS);

    // main game loop
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Keyboard::W)
                continue;

            if (event.type == sf::Keyboard::S)
                continue;
            
            if (event.type == sf::Keyboard::A)
                continue;
            
            if (event.type == sf::Keyboard::D)
                continue;
        }
        
        // update player's position
        player.setPosition(player.getPosition().x + PLAYER_SPEED_X, player.getPosition().y + PLAYER_SPEED_Y);

        if (player.getPosition().x + CIRCLE_RADIUS >= WINDOW_WIDTH || player.getPosition().x - CIRCLE_RADIUS < 0)
            PLAYER_SPEED_X *= -1;
        
        if (player.getPosition().y + CIRCLE_RADIUS >= WINDOW_HEIGHT || player.getPosition().y - CIRCLE_RADIUS < 0)
            PLAYER_SPEED_Y *= -1;

        // clear window
        window.clear(sf::Color::Black);

        // render scene
        window.draw(player);

        // display scene
        window.display();
    }

    return 0;
}