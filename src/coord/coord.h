#ifndef COORD_H
#define COORD_H

class Coord {
public:
    int x;
    int y;

    Coord(int _x, int _y) : x(_x), y(_y) {}

    bool operator==(const Coord& other) const {
        return x == other.x && y == other.y;
    }
};

#endif // COORD_H
