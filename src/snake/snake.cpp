#include "snake.h"

Snake::Snake() : live(true) {}

void Snake::addCoord(const Coord coord) {
    this->snakeCoords.push_back(coord);
}

void Snake::removeCoord() {
    if (!this->snakeCoords.empty()) {
        this->snakeCoords.pop_back();
    }
}

const std::vector<Coord> Snake::getSnakeCoords() const {
    return this->snakeCoords;
}

const bool Snake::isAlive() const {
    return this->live;
}

void Snake::setDirection(Direction direction) {
    this->direction = direction;
}

const Direction Snake::getDirection() const {
    return this->direction;
}

const Coord Snake::getDirectionVector() const {
    switch (this->direction) {
        case Direction::UP:
            return Coord(0, -1);
        case Direction::DOWN:
            return Coord(0, 1);
        case Direction::LEFT:
            return Coord(-1, 0);
        case Direction::RIGHT:
            return Coord(1, 0);
    }
}

void Snake::checkIsAlive() {
    Coord headCoord = this->snakeCoords.front();
    if (headCoord.x < 0 || headCoord.x >= 10 || headCoord.y < 0 || headCoord.y >= 10) {
        this->live = false;
        return;
    }

    for (int i = 0; i < this->snakeCoords.size(); i++) {
        if (headCoord == this->snakeCoords[i]) {
            this->live = false;
            return;
        }
    }

    this->live = true;
}

void Snake::setStartPosition(Size fieldSize) {
    this->snakeCoords.clear();

    Coord startSnakeCoord = Coord(fieldSize.width / 2, fieldSize.height / 2);
    std::vector<Coord> startSnakeCoords = {
        startSnakeCoord,
        Coord(startSnakeCoord.x, startSnakeCoord.y + 1),
        Coord(startSnakeCoord.x, startSnakeCoord.y + 2),
    };

    this->snakeCoords = startSnakeCoords;
}
