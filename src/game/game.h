#ifndef GAME_H
#define GAME_H

#include "../field/field.h"
#include "../apple/apple.h"
#include "../snake/snake.h"

class Game {
private:
    Field field;
    Snake snake;
    Apple apple;
    int score;

public:
    Game();

    void gameStep();

    const Field getField() const;

    const Snake getSnake() const;

    const int getScore() const;

    const Apple getApple() const;

    void step();
};

#endif // GAME_H
