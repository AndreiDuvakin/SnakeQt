#ifndef FIELD_H
#define FIELD_H

#include <utility>
#include "../size/size.h"

class Field {
private:
    const Size size;

public:
    Field();

    const Size getSize() const;
};

#endif // FIELD_H
