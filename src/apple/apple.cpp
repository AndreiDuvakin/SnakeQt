#include "apple.h"
#include <cstdlib>
#include <ctime>

Apple::Apple(int _maxX, int _maxY, std::vector<Coord> snakeCoord) : coord(0, 0), maxX(_maxX), maxY(_maxY) {
    regenerateCors(snakeCoord);
    srand(time(nullptr));
}

void Apple::regenerateCors(std::vector<Coord> snakeCoord) {
    bool isOnSnake;

    do {
        if (this->maxX != 0) {
            this->coord.x = rand() % this->maxX;
        } else {
            this->coord.x = 0;
        }

        if (this->maxY != 0) {
            this->coord.y = rand() % this->maxY;
        } else {
            this->coord.y = 0;
        }

        isOnSnake = false;
        for (int i = 0; i<snakeCoord.size();i++) {
            if (this->coord == snakeCoord[i]) {
                isOnSnake = true;
                break;
            }
        }
    } while (isOnSnake);
}

const Coord Apple::getCors() const {
    return this->coord;
}
