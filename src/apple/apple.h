#ifndef APPLE_H
#define APPLE_H

#include <utility>
#include "../coord/coord.h"

class Apple {
private:
    Coord coord;
    int maxX;
    int maxY;

public:
    Apple(int maxX, int maxY);

    const Coord getCors() const;

    void regenerateCors();
};

#endif // APPLE_H
