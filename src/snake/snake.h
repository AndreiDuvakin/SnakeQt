#ifndef SNAKE_H
#define SNAKE_H

#include "../coord/coord.h"
#include "../size/size.h"
#include "../apple/apple.h"
#include <vector>

enum class Direction {
    UP,
    DOWN,
    LEFT,
    RIGHT
};

class Snake {
private:
    std::vector<Coord> snakeCoords;
    bool live;
    Direction direction;

    void checkIsAlive();

public:
    Snake();

    void setStartPosition(Size fieldSize);

    void addCoord(const Coord coord);

    void removeCoord();

    const std::vector<Coord> getSnakeCoords() const;

    const bool isAlive() const;

    void setDirection(Direction direction);

    const Direction getDirection() const;

    const Coord getDirectionVector() const;

    void step(Apple apple);
};

#endif // SNAKE_H
