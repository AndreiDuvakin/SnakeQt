#include "apple.h"
#include <cstdlib>
#include <ctime>

Apple::Apple(int _maxX, int _maxY) : coord(0, 0), maxX(_maxX), maxY(_maxY) {
    srand(time(nullptr));
    regenerateCors();
}

void Apple::regenerateCors() {
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
}

const Coord Apple::getCors() const {
    return this->coord;
}
