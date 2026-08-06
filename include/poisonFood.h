#pragma once 
#include "food.h"
/**
 * @class poisonFoodFood 
 * @brief A subclass of class Food, with effect of shrinking the snake's legnth
 */

class poisonFood: public Food{
public:
    /**
     * @brief Constructs a poisonFood object using member initializer list to initialize
     * @brief the underlying Food object first, before running the constructor body.
     * @param position Initial grid position of the food.
     */
    poisonFood(sf::Vector2i position):Food(position) {};

    /**
     * @brief Specifies the effect of poisonFood on the snake
     */
    void effect(Snake& snake) const override;

    /**
     * @brief Specifies the effect of poisonFood on the snake
     */
    void draw(sf::RenderWindow& window) const override;
};