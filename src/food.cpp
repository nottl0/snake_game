#include "food.h"
#include "constants.h"

// FIX THE FOOD POSITIONING TO START IN SMALLER BOX
// AND INCREASE WHEN THE SNAKE GROWS

Food::Food(sf::Vector2i pos) : counter(0){
    position = pos;
};

Food::~Food() = default;

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