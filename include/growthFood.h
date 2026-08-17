#pragma once 
#include "food.h"
#include <iostream>

/**
 * @class growthFood 
 * @brief A subclass of class Food, with effect of increasing the snake legnth
 */

class growthFood: public Food{
public:
    /**
     * @brief Constructs a growthFood object using member initializer list to initialize
     * @brief the underlying Food object first, before running the constructor body. 
     * @brief Also creates a texture before sprite, and sprite before the growthFood constructor.
     * @param position Initial grid position of the food.
     */
    growthFood(sf::Vector2i position):Food(position), texture("assets/mouse.jpeg"), sprite(texture){
        if (!texture.loadFromFile("assets/mouse.jpeg")) {
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
     * @brief Specifies the effect of growthFood on the snake
     */
    void effect(Snake& snake) const override;

    /**
     * @brief Specifies the effect of growthFood on the snake
     */
    void draw(sf::RenderWindow& window) const override;

private:
    sf::Texture texture;
    sf::Sprite sprite;
};
