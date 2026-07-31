#include "food.h"
#include "constants.h"

// FIX THE FOOD POSITIONING TO START IN SMALLER BOX
// AND INCREASE WHEN THE SNAKE GROWS

Food::Food(sf::Vector2i pos) : counter(0){
    position = pos;
};

Food::~Food() = default;

void Food::respawn(sf::Vector2i pos){
    counter = 0;
    position = pos;
};

void Food::incrementCounter() {
    counter += 1;
};

sf::Vector2i Food::getPosition() const {
    return position;
};

bool Food::shouldRespawn() const {
    if (counter >= foodShelfLife){
        return true;
    }
    else{
        return false;
    }
};

void Food::draw(sf::RenderWindow& window) const {
    sf::RectangleShape rect({CELL_SIZE, CELL_SIZE});
    rect.setPosition(sf::Vector2f((position.x * CELL_SIZE) % WINDOW_WIDTH, (position.y * CELL_SIZE) % WINDOW_HEIGHT));
    rect.setFillColor(sf::Color::Black);
    window.draw(rect);
};