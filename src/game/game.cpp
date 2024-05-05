#include "game.h"
#include "../apple/apple.h"
#include "../field/field.h"


Game::Game() : score(0), apple(this->field.getSize().width, this->field.getSize().height, this->snake.getSnakeCoords()) {
    this->snake.setStartPosition(this->field.getSize());
}

const Field Game::getField() const {
    return this->field;
}

Snake &Game::getSnake() {
    return this->snake;
}

Apple &Game::getApple() {
    return this->apple;
}

const int Game::getScore() const {
    return this->score;
}

void Game::step() {
    this->snake.step(this->apple);
}
