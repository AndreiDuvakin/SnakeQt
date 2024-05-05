#include "game.h"


Game::Game() : apple(this->field.getSize().width, this->field.getSize().height), score(0) {
    this->snake.setStartPosition(this->field.getSize());
}

const Field Game::getField() const {
    return this->field;
}

const Snake Game::getSnake() const {
    return this->snake;
}

const Apple Game::getApple() const {
    return this->apple;
}

const int Game::getScore() const {
    return this->score;
}

void Game::step() {
    this->snake.step(this->apple);
}
