#pragma once
#include <random>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "constants.h"
#include "food.h"
#include "snake.h"

 /**
 * @class Game
 * @brief The main class from which the game object is created.
 *
 * Handles the game flow as well as its components.
 */
class Game {
private:
    sf::Clock clock;            ///> Clock to measure the elapsed time.
    int moveDelay;              ///> The time difference between state changes in the game.
    std::mt19937 gen;           ///> Random number generator.
    std::unique_ptr<Food> food; ///> The pointer to an object that inherits from food.
    Snake snake;                ///> The snake object.
    sf::RenderWindow window;    ///> The main game window.
    bool isOver;                ///> The game over state. False is the game is still being played.

    /**
    * @brief A function that generates a random position on the window in terms of cells (not pixels).
    * @returns A Vector of (x, y) with x the row, and y the column of the random cell.
    **/
    sf::Vector2i getRandPos() {
        std::uniform_int_distribution<> w(0, WINDOW_WIDTH - 1);
        std::uniform_int_distribution<> h(0, WINDOW_HEIGHT - 1);
        return { w(gen)/CELL_SIZE, h(gen)/CELL_SIZE };
    }

public:
    /**
     * @brief Constructs a Game object.
     */
    Game();

    /**
     * @brief Runs the game as long as the window is open
     */
    void run();

    /**
     * @brief Processes events triggered by player such as moving/restarting.
     */
    void processEvents();

    /**
     * @brief Randomly choose what food to spawn in the game.
     */
    void spawnRandomFood(sf::Vector2i pos);

    /**
     * @brief Updates the states of game objects one step.
     */
    void update();
    
    /**
     * @brief Displays the current state of the game on the window.
     */
    void render();

    /**
     * @brief Ends the game by setting isOver = true.
     */
    void endGame();

    /**
     * @brief Displays the window indicating that the game ended.
     */
    void drawEndGameWindow();

    /**
     * @brief Restarts the game.
     */
    void resetGame();
};