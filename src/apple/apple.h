#ifndef APPLE_H
#define APPLE_H

#include <utility>
#include "../coord/coord.h"

class Apple {
private:
    Coord coord;

public:
    Apple(int maxX, int maxY);

    const Coord getCors() const;

    void regenerateCors(int maxX, int maxY);
};

#endif // APPLE_H
