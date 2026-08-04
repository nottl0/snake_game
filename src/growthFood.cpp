#include "growthFood.h"
#include "snake.h"

void growthFood::effect(Snake& snake) const{
    snake.grow();
};