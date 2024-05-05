#ifndef APPLE_H
#define APPLE_H

#include <utility>
#include <vector>
#include "../coord/coord.h"

class Apple {
private:
    Coord coord;
    int maxX;
    int maxY;

public:
    Apple(int maxX, int maxY, std::vector<Coord> snakeCoord);

    const Coord getCors() const;

    void regenerateCors(std::vector<Coord> snakeCoord);
};

#endif // APPLE_H
