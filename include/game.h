#pragma once
#include <random>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "constants.h"
#include "food.h"
#include "snake.h"

class Game {
private:
    sf::Clock clock;
    int moveDelay;
    std::mt19937 gen;
    Food food;
    Snake snake;
    sf::RenderWindow window;
    bool isOver;

    sf::Vector2i getRandPos() {
        std::uniform_int_distribution<> w(0, WINDOW_WIDTH - 1);
        std::uniform_int_distribution<> h(0, WINDOW_HEIGHT - 1);
        return { w(gen)/CELL_SIZE, h(gen)/CELL_SIZE };
    }

public:
    Game();
    void run();
    void processEvents();
    void update();
    void render();
    void endGame();
    void drawEndGameWindow();
    void resetGame();
};