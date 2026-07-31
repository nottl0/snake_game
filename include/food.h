#pragma once
#include <SFML/Graphics.hpp>

class Food{
    sf::Vector2i position;
    int counter;
    const int foodShelfLife{100};

public:
    Food(sf::Vector2i position);
    ~Food();

    void respawn(sf::Vector2i position);
    void incrementCounter();
    void draw(sf::RenderWindow&) const;
    sf::Vector2i getPosition() const;
    bool shouldRespawn() const;
};