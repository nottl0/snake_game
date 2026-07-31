#include "game.h"
#include <iostream>

sf::Font font;

Game::Game() : moveDelay(MOVE_DELAY),
          gen(std::random_device{}()),
          window(sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}), "sssnake game"),
          food(getRandPos()),
          snake(),
          isOver(false)
    {
        if (!font.openFromFile("/Users/aminaizbassar/Documents/snake_game/typographica-font/Typographica-Blp5.ttf")) {
            std::cout << "Failed to load font\n";
    }
}

void Game::run() {
    // run the program as long as the window is open
    while (window.isOpen()) {
        processEvents();
        if (!isOver){
            update();
            render();
        }
        else{
            drawEndGameWindow();
        }
    }
};

void Game::resetGame() {
    food.respawn(getRandPos());
    snake = Snake();
    isOver = false;
};

void Game::endGame() {
    isOver = true;
};

void Game::drawEndGameWindow(){

    window.clear(sf::Color::White);

    sf::Text text(font, "Game Over\nPress R to Restart");
    text.setCharacterSize(40);
    text.setStyle(sf::Text::Bold);
    text.setFillColor(sf::Color::Black);

    window.draw(text);
    window.display();
}

void Game::processEvents(){
    // check all the window's events that were triggered since the last iteration of the loop
    while (const std::optional event = window.pollEvent())
    {
        // "close requested" event: we close the window
        if (event->is<sf::Event::Closed>()){
            window.close();
        }
        if (const sf::Event::KeyPressed* key = event -> getIf<sf::Event::KeyPressed>()){
            if (key -> code == sf::Keyboard::Key::Up) {
                snake.setNewDirection(Direction::UP);
            }
            else if (key -> code == sf::Keyboard::Key::Down) {
                snake.setNewDirection(Direction::DOWN);
            }
            else if (key -> code == sf::Keyboard::Key::Right) {
                snake.setNewDirection(Direction::RIGHT);
            }
            else if (key -> code == sf::Keyboard::Key::Left){
                snake.setNewDirection(Direction::LEFT);
            }
            else if (key -> code == sf::Keyboard::Key::R) {
                resetGame();
            }
        }   
    }
};

void Game::render(){
    //clear the window
    window.clear(sf::Color::White);

    // draw the snake and food
    snake.draw(window);
    food.draw(window);
    // display all that's drawn on the window
    window.display();
};

void Game::update(){
    if (clock.getElapsedTime().asSeconds() >= moveDelay) {
        // update snake's position
        snake.changeDirection();
        snake.move();
        food.incrementCounter();
        
        if (snake.getHeadPos() == food.getPosition()){
            snake.grow();
            food.respawn(getRandPos());
        };
        if (food.shouldRespawn()){
            food.respawn(getRandPos());
        };
        if (!snake.getPulse()){
            endGame();
        }
        clock.restart();
    }
};

