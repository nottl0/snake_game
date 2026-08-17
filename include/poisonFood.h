#pragma once 
#include "food.h"
#include <iostream>

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
    poisonFood(sf::Vector2i position):Food(position), texture("assets/bomb.jpg"), sprite(texture){
        if (!texture.loadFromFile("assets/bomb.jpg")) {
            std::cout << "Failed to load food texture\n";
        } else {
            std::cout << "Texture loaded OK, size: " << texture.getSize().x << "x" << texture.getSize().y << "\n";
        }

        // scale image down/up to match one grid cell
        sf::Vector2u texSize = texture.getSize();
        
        sprite.setScale(sf::Vector2f(
            static_cast<float>(CELL_SIZE) / texSize.x,
            static_cast<float>(CELL_SIZE) / texSize.y
        ));

        sprite.setPosition(sf::Vector2f(
            (getPosition().x * CELL_SIZE) % WINDOW_WIDTH,
            (getPosition().y * CELL_SIZE) % WINDOW_HEIGHT
        ));
    };

    /**
     * @brief Specifies the effect of poisonFood on the snake
     */
    void effect(Snake& snake) const override;

    /**
     * @brief Specifies the effect of poisonFood on the snake
     */
    void draw(sf::RenderWindow& window) const override;

private:

    sf::Texture texture;
    sf::Sprite sprite;

};