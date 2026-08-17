#pragma once
#include <SFML/Graphics.hpp>
#include "snake.h"

 /**
 * @class Food
 * @brief Parent class for all types of food.
 *
 * Handles the food's position and lifespan.
 */
class Food{
    
    sf::Vector2i position;      ///< Grid position of the food, in cells (not pixels).
    int counter;                ///< Tracks how many ticks/moves have passed since spawning.
    const int foodShelfLife{15}; ///< Maximum allowed counter value before the food expires.

public:
    /**
     * @brief Constructs a Food object at the given position.
     * @param position Initial grid position of the food.
     */
    Food(sf::Vector2i position);

    // made virtual to be able to destruct the subclass object
    // if its not virtual when unique_ptr<Food> deletes the object it
    // only calls ~Food()
    // when this is virtual the subclass destructor is called first, then ~Food()  
    virtual ~Food();

    /**
     * @brief Advances the food's internal counter by one tick.
     *
     * Called once per game tick; once counter reaches foodShelfLife,
     * shouldRespawn() will return true.
     */
    void incrementCounter();

    /**
     * @brief Returns the food's current grid position.
     */
    sf::Vector2i getPosition() const;

    /**
     * @brief Tells if the fruit should respawn in the window based on the game state.
     * @returns true if the food shoudl respan on the window.
     */
    bool shouldRespawn() const;

    /**
     * @brief Specifies the effect of each subtype of food on the snake and
     * @brief applies it.
     * @brief A virtual method
     */
    virtual void effect(Snake& snake) const=0;

    /**
     * @brief Draws the food to the given render window.
     * @param window The SFML window to draw onto.
     */
    virtual void draw(sf::RenderWindow& window) const=0;
}; 