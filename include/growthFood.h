#pragma once 
#include "food.h"
/**
 * @class growthFood 
 * @brief A subclass of class Food, with effect of increasing the snake legnth
 */

class growthFood: public Food{
public:
    /**
     * @brief Constructs a growthFood object using member initializer list to initialize
     * @brief the underlying Food object first, before running the constructor body.
     * @param position Initial grid position of the food.
     */
    growthFood(sf::Vector2i position):Food(position) {};

    /**
     * @brief Specifies the effect of growthFood on the snake
     */
    void effect(Snake& snake) const override;

    /**
     * @brief Specifies the effect of growthFood on the snake
     */
    void draw(sf::RenderWindow& window) const override;
};