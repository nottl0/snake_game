#include "deathFood.h"
#include "snake.h"
#include "constants.h"

void deathFood::effect(Snake& snake) const{
    snake.kill();
};

void deathFood::draw(sf::RenderWindow& window) const {
    window.draw(sprite);
};