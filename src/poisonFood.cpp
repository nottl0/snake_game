#include "poisonFood.h"
#include "snake.h"
#include "constants.h"

void poisonFood::effect(Snake& snake) const{
    snake.shrink();
};

void poisonFood::draw(sf::RenderWindow& window) const {
    sf::RectangleShape rect({CELL_SIZE, CELL_SIZE});
    rect.setPosition(sf::Vector2f((getPosition().x * CELL_SIZE) % WINDOW_WIDTH, (getPosition().y * CELL_SIZE) % WINDOW_HEIGHT));
    rect.setFillColor(sf::Color::Red);
    window.draw(rect);
};