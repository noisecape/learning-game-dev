#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>


int main()
{

    int width = 640;
    int height = 480;
    int frameRate = 60;

    // create window
    sf::RenderWindow window(sf::VideoMode(width, height), "Simple Game");
    // create player --> just a triangle
    sf::RectangleShape player(sf::Vector2f(width/4, height/4));
    player.setPosition(width/2, height/2);

    player.setFillColor(sf::Color::Blue);

    // limit framerate to be the one of the monitor
    window.setVerticalSyncEnabled(true);
    // limit framerate to 60 fps anyway
    window.setFramerateLimit(frameRate);
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            // Check if "W" key is pressed
            if (event.key.code == sf::Keyboard::W) {
                player.setPosition(player.getPosition().x, player.getPosition().y - 5);
            }

            if (event.key.code == sf::Keyboard::S)
            {
                player.setPosition(player.getPosition().x, player.getPosition().y + 5);
            }

            if (event.key.code == sf::Keyboard::A)
            {
                player.setPosition(player.getPosition().x - 5, player.getPosition().y);
            }

            if (event.key.code == sf::Keyboard::D)
            {
                player.setPosition(player.getPosition().x + 5, player.getPosition().y);
            }

        }

        window.clear();
        window.draw(player);
        window.display();
    }

    return 0;
}