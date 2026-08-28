#include "snake.h"
#include "constants.h"
#include <SFML/Window.hpp>
#include "roundedRectangle.h"

// Maps each direction to a vector representing the corresponding change in position 
const std::unordered_map<Direction, sf::Vector2i> moveDirections = {
    {Direction::UP, sf::Vector2i(0, -1)},
    {Direction::RIGHT, sf::Vector2i(1, 0)},
    {Direction::DOWN, sf::Vector2i(0, 1)},
    {Direction::LEFT, sf::Vector2i(-1, 0)}
};

// Initializes the snake in the middle of the window, facing right, with a length of INITIAL_SNAKE_LENGTH
Snake::Snake() : direction{Direction::RIGHT}, newDirection{Direction::RIGHT}{
    int startX = WINDOW_WIDTH / (2 * CELL_SIZE);
    int startY = WINDOW_HEIGHT / (2 * CELL_SIZE);
    for (int i = 0; i < INITIAL_SNAKE_LENGTH; ++i) {
        body.push_back({startX - i, startY});
    }
};

// Default destructor, no special cleanup needed
Snake::~Snake() = default;

// Draws the snake on the game window. Doesn't show righ away, the double buffering of the window will handle that when display() is called in main loop
void Snake::draw(sf::RenderWindow& window) const {
    int bodyLength = body.size();
    float rotationDegrees = 0.f;
    switch (direction) {
    case Direction::UP:    rotationDegrees = 0.f;   break;
    case Direction::RIGHT: rotationDegrees = 90.f;  break;
    case Direction::DOWN:  rotationDegrees = 180.f; break;
    case Direction::LEFT:  rotationDegrees = 270.f; break;
    }   
    
    sf::Vector2i h = body[0];
    sf::Vector2i t = body.back();
    RoundedRectangleShape head({CELL_SIZE, CELL_SIZE}, 8);
    // Set the origin to the center of the cell to rotate around origin without misaligning head from body
    // Only used for setRotation and setPosition
    head.setOrigin({CELL_SIZE / 2.f, CELL_SIZE / 2.f});
    // Adjust the position to be shifted so that center of head is in the cell center
    head.setPosition(sf::Vector2f(
        (h.x * CELL_SIZE) % WINDOW_WIDTH + CELL_SIZE / 2.f,
        (h.y * CELL_SIZE) % WINDOW_HEIGHT + CELL_SIZE / 2.f
    ));
    head.setFillColor(sf::Color::Green);
    head.setRotation(sf::degrees(rotationDegrees));
    window.draw(head);

    // Body movement
    for (int i = 1; i < bodyLength - 1; i++) {
        sf::RectangleShape rect({CELL_SIZE, CELL_SIZE});
        rect.setPosition(sf::Vector2f((body[i].x * CELL_SIZE) % WINDOW_WIDTH, (body[i].y * CELL_SIZE) % WINDOW_HEIGHT));
        rect.setFillColor(sf::Color::Green);
        window.draw(rect);
    }

    
    if (bodyLength < 2){
        return;
    };

    Direction direction;
    sf::Vector2i difference = body[bodyLength - 2] - t;
    if (difference == sf::Vector2i{0, -1}){direction = Direction::UP;}
    else if (difference == sf::Vector2i{1, 0}){direction = Direction::RIGHT;}
    else if (difference == sf::Vector2i{0, 1}){direction = Direction::DOWN;}
    else {direction = Direction::LEFT;};

    switch (direction) {
    case Direction::UP:    rotationDegrees = 0.f;   break;
    case Direction::RIGHT: rotationDegrees = 90.f;  break;
    case Direction::DOWN:  rotationDegrees = 180.f; break;
    case Direction::LEFT:  rotationDegrees = 270.f; break;
    } 
    
    sf::ConvexShape tail(3);
    tail.setOrigin({CELL_SIZE / 2.f, CELL_SIZE / 2.f});
    tail.setPosition(sf::Vector2f(
        (t.x * CELL_SIZE) % WINDOW_WIDTH + CELL_SIZE / 2.f,
        (t.y * CELL_SIZE) % WINDOW_HEIGHT + CELL_SIZE / 2.f
    ));
    
    tail.setPoint(0, sf::Vector2f {0, 0});
    tail.setPoint(1, sf::Vector2f {CELL_SIZE, 0});
    tail.setPoint(2, sf::Vector2f {CELL_SIZE / 2, CELL_SIZE});
    tail.setFillColor(sf::Color::Green);
    tail.setRotation(sf::degrees(rotationDegrees));
    window.draw(tail);
    
};

// Moves the snake in the current movement direction 
void Snake::move() {
    int snakeLen = body.size();
    for (int i = snakeLen - 1; i > 0; --i) {
        body[i] = body[i-1];
    }
    body[0] += moveDirections.at(direction);
    
    // Wrap around grid boundaries
    int cols = WINDOW_WIDTH / CELL_SIZE;
    int rows = WINDOW_HEIGHT / CELL_SIZE;
    body[0].x = (body[0].x % cols + cols) % cols;
    body[0].y = (body[0].y % rows + rows) % rows;
};

void Snake::changeDirection() {
    // Prevent the snake from reversing on itself
    if (direction == newDirection) {
        return;
    }
    else if ((direction == Direction::UP && newDirection != Direction::DOWN) ||
        (direction == Direction::RIGHT && newDirection != Direction::LEFT) ||
        (direction == Direction::DOWN && newDirection != Direction::UP) ||
        (direction == Direction::LEFT && newDirection != Direction::RIGHT)) {
        direction = newDirection;
    }
};

void Snake::setNewDirection(Direction direction) {
    // Prevent the snake from reversing on itself
    newDirection = direction;
};

void Snake::grow() {
    // Grow the snake in length 
    int snakeLen = body.size();
    sf::Vector2i tmp = body[snakeLen - 1];
    body.push_back(tmp);
};

void Snake::shrink() {
    body.pop_back();
};

sf::Vector2i Snake::getHeadPos() const{
    return body[0];
};

bool Snake::getPulse() const{
    int snakeLen = body.size();
    sf::Vector2i headPos = getHeadPos();
    for (int i=1; i<snakeLen; ++i) {
        if (headPos == body[i]){
            return false;
        }
    }
    return true;
}