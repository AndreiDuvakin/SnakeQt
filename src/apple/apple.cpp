#include "apple.h"
#include <cstdlib>

Apple::Apple(int maxX, int maxY) : coord(0, 0) {
    regenerateCors(maxX, maxY);
}

void Apple::regenerateCors(int maxX, int maxY) {
    if (maxX != 0) {
        this->coord.x = rand() % maxX;
    } else {
        this->coord.x = 0;
    }

    if (maxY != 0) {
        this->coord.y = rand() % maxY;
    } else {
        this->coord.y = 0;
    }
}

const Coord Apple::getCors() const {
    return this->coord;
}
