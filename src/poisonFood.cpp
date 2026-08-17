#include "poisonFood.h"
#include "snake.h"
#include "constants.h"

void poisonFood::effect(Snake& snake) const{
    snake.shrink();
};

void poisonFood::draw(sf::RenderWindow& window) const {
    window.draw(sprite);
};