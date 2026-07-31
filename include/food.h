#pragma once
#include <SFML/Graphics.hpp>

 /**
 * @class Food
 * @brief Parent class for all types of food.
 *
 * Handles the food's position and lifespan.
 */
class Food{
    
    sf::Vector2i position;      ///< Grid position of the food, in cells (not pixels).
    int counter;                ///< Tracks how many ticks/moves have passed since spawning.
    const int foodShelfLife{5}; ///< Maximum allowed counter value before the food expires.

public:
    /**
     * @brief Constructs a Food object at the given position.
     * @param position Initial grid position of the food.
     */
    Food(sf::Vector2i position);
    ~Food();
    
    /**
     * @brief Moves the food to a new position and resets its lifespan counter.
     * @param position New grid position for the food.
     */
    void respawn(sf::Vector2i position);

    /**
     * @brief Advances the food's internal counter by one tick.
     *
     * Called once per game tick; once counter reaches foodShelfLife,
     * shouldRespawn() will return true.
     */
    void incrementCounter();

    /**
     * @brief Draws the food to the given render window.
     * @param window The SFML window to draw onto.
     */
    void draw(sf::RenderWindow& window) const;

    /**
     * @brief Returns the food's current grid position.
     */
    sf::Vector2i getPosition() const;

    /**
     * @brief Tells if the fruit should respawn in the window based on the game state.
     * @returns true if the food shoudl respan on the window.
     */
    bool shouldRespawn() const;
}; 