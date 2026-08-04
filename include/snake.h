#pragma once 
#include "constants.h"
#include <vector>
#include <SFML/Graphics.hpp>

// Directions in which the snake is allowed to move.
enum class Direction {
    UP,
    RIGHT,
    DOWN,
    LEFT
};

 /**
 * @class Snake
 * @brief The class for controlling the snake object of the game.
 *
 * Handles the snakes position, movement, direction and lifespan.
 */
class Snake {
    
    Direction direction;            ///> Current direction of the snakes movement (where the head is pointing).
    std::vector<sf::Vector2i> body; ///> Positions of the game window cells occupied by the snake's body.
    Direction newDirection;         ///> Where the direction of the snakes movement should point in the next step. Set by player.
    
public:
    /**
     * @brief Constructs a Snake object.
     */
    Snake();
    ~Snake();

    /**
     * @brief Changes the snakes body position to reflect movement in the current direction.
     */
    void move();

    /**
     * @brief Increases snake size when eating.
     */
    void grow();
    
    /**
     * @brief Changes the direction where the snake is going based on the newDirection.
     */
    void changeDirection();

    /**
     * @brief Sets the newDirection attribute based on param.
     * @param newDirection one of the 4 directions from Direction enum class.
     */
    void setNewDirection(Direction newDirection);

    /**
     * @brief Gets the position of snakes head.
     * @returns Current head coordinates.
     */
    sf::Vector2i getHeadPos() const;

    /**
     * @brief Sets the newDirection attribute based on param.
     * @returns true if the snake is still alive, false otherwise.
     */
    bool getPulse() const;

    /**
     * @brief Draws the snake to the given render window.
     * @param The SFML window to draw onto.
     */
    void draw(sf::RenderWindow& window) const;
};