#pragma once 
#include "constants.h"
#include <vector>
#include <SFML/Graphics.hpp>

enum class Direction {
    UP,
    RIGHT,
    DOWN,
    LEFT
};

class Snake {
    Direction direction;
    std::vector<sf::Vector2i> body; // positions of the snake's body
    Direction newDirection;
public:
    Snake();
    ~Snake();

    void move();
    void grow();
    bool checkCollision() const;
    void changeDirection();
    void setNewDirection(Direction newDirection);
    sf::Vector2i getHeadPos() const;
    bool getPulse() const;
    void draw(sf::RenderWindow& window) const;
};