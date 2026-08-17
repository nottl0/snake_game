#include "growthFood.h"
#include "snake.h"
#include "constants.h"

void growthFood::effect(Snake& snake) const{
    snake.grow();
};

void growthFood::draw(sf::RenderWindow& window) const {
    window.draw(sprite);
};