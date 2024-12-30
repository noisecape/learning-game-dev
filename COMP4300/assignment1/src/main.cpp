#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <cstdlib> // needed to import rand() and srand()
#include <ctime> // needed to import time()
#include <vector> // load vector type to store all the shapes
#include <random>


int main()
{
    // declare a bunch of consts
    const int WINDOW_WIDTH = 1280;
    const int WINDOW_HEIGHT = 720;
    const int WINDOW_FPS = 60;
    const float CIRCLE_RADIUS = 25.0f;
    float SPEED_X = 2.5f;
    float SPEED_Y = 2.5f;
    const float SHAPES[] = {20.0f, 25.0f, 30.0f, 35.0f, 40.0f, 45.0f, 50.0f, 60.0f, 80.0f};
    
    // get the size of the array, this is useful for random sampling
    const size_t sizeShapesArray = sizeof(SHAPES) / sizeof(SHAPES[0]);
    
    std::vector<sf::Shape*> entities; // vector of type Shape, to store all the possible shape types.

    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Assignment 1");

    // define random engine
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> randDistX(0, WINDOW_WIDTH);
    std::uniform_int_distribution<> randDistY(0, WINDOW_HEIGHT);

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
    int randomPosX = randDistX(gen);
    int randomPosY = randDistY(gen);
    shape1->setPosition(randomPosX, randomPosY);
    entities.push_back(shape1);

    float randomShapeTriangle = SHAPES[std::rand() % sizeShapesArray];
    sf::CircleShape* triangle = new sf::CircleShape(randomShapeTriangle, 3);
    triangle->setFillColor(sf::Color::Green);
    randomPosX = randDistX(gen);
    randomPosY = randDistY(gen);
    triangle->setPosition(randomPosX, randomPosY);
    entities.push_back(triangle);

    float randomShapePentagon = SHAPES[std::rand() % sizeShapesArray];
    sf::CircleShape* pentagon = new sf::CircleShape(randomShapePentagon, 5);
    pentagon->setFillColor(sf::Color::Red);
    randomPosX = randDistX(gen);
    randomPosY = randDistY(gen);
    pentagon->setPosition(randomPosX, randomPosY);
    entities.push_back(pentagon);

    float randomShapeOctagon = SHAPES[std::rand() % sizeShapesArray];
    sf::CircleShape* octagon = new sf::CircleShape(randomShapeOctagon, 8);
    octagon->setFillColor(sf::Color::Yellow);
    randomPosX = randDistX(gen);
    randomPosY = randDistY(gen);
    octagon->setPosition(randomPosX, randomPosY);
    entities.push_back(octagon);

    std::vector<float> ALL_SPEEDS_X;
    std::vector<float> ALL_SPEEDS_Y;

    for (int i = 0; i<entities.size(); i++)
    {
        ALL_SPEEDS_X.push_back(SPEED_X);
        ALL_SPEEDS_Y.push_back(SPEED_Y);
    }

    // main game loop
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // clear window
        window.clear(sf::Color::Black);
        

        for (int i=0; i < entities.size(); i++)
        {   
            sf::FloatRect bounds = entities[i]->getGlobalBounds();

            if (bounds.top < 0 || bounds.top + bounds.height > WINDOW_HEIGHT)
            {
                ALL_SPEEDS_Y[i] *= -1;
            }

            if (bounds.left < 0 || bounds.left + bounds.width > WINDOW_WIDTH)
            {
                ALL_SPEEDS_X[i] *= -1;
            }
            entities[i]->setPosition(entities[i]->getPosition().x + ALL_SPEEDS_X[i], entities[i]->getPosition().y + ALL_SPEEDS_Y[i]);
            window.draw(*entities[i]);
        }
        // display scene
        window.display();
    }

    return 0;
}