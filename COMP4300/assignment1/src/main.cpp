#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <cstdlib> // needed to import rand() and srand()
#include <ctime> // needed to import time()
#include <vector> // load vector type to store all the shapes


int main()
{
    // declare a bunch of consts
    const int WINDOW_WIDTH = 1280;
    const int WINDOW_HEIGHT = 720;
    const int WINDOW_FPS = 60;
    const float CIRCLE_RADIUS = 25.0f;
    float SPEED_X = 2.5f;
    float SPEED_Y = 2.5f;
    const float SHAPES[] = {80.0f, 90.0f, 100.0f, 120.0f, 150.0f, 180.0f, 200.0f, 220.0f, 250.0f};
    
    // get the size of the array, this is useful for random sampling
    const size_t sizeShapesArray = sizeof(SHAPES) / sizeof(SHAPES[0]);
    
    std::vector<sf::Shape*> entities; // vector of type Shape, to store all the possible shape types.

    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Assignment 1");

    // set window frame rate
    window.setFramerateLimit(WINDOW_FPS);

    // create the players
    sf::CircleShape* player = new sf::CircleShape(CIRCLE_RADIUS);
    player->setFillColor(sf::Color::Green);
    player->setPosition(WINDOW_WIDTH / 2.0f, WINDOW_HEIGHT / 2.0f);
    player->setOrigin(CIRCLE_RADIUS, CIRCLE_RADIUS);
    entities.push_back(player);

    // set random seed based on current second
    std::srand(time(NULL));

    // use the remainder operator to get the index
    float randX = SHAPES[std::rand() % sizeShapesArray];
    float randY = SHAPES[std::rand() % sizeShapesArray];
    sf::RectangleShape* shape1 = new sf::RectangleShape(sf::Vector2f(randX, randY));
    shape1->setFillColor(sf::Color::Blue);
    entities.push_back(shape1);

    float randomShapeTriangle = SHAPES[std::rand() % sizeShapesArray];
    sf::CircleShape* triangle = new sf::CircleShape(randomShapeTriangle, 3);
    triangle->setFillColor(sf::Color::Green);
    entities.push_back(triangle);

    float randomShapePentagon = SHAPES[std::rand() % sizeShapesArray];
    sf::CircleShape* pentagon = new sf::CircleShape(randomShapePentagon, 5);
    pentagon->setFillColor(sf::Color::Red);
    entities.push_back(pentagon);

    float randomShapeOctagon = SHAPES[std::rand() % sizeShapesArray];
    sf::CircleShape* octagon = new sf::CircleShape(randomShapeOctagon, 8);
    octagon->setFillColor(sf::Color::Yellow);
    entities.push_back(octagon);

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

        // clear window
        window.clear(sf::Color::Black);
        for (auto &e: entities)
        {
            e->setPosition(e->getPosition().x + SPEED_X, e->getPosition().y + SPEED_Y);
            window.draw(*e);
        }

        // display scene
        window.display();
    }

    return 0;
}