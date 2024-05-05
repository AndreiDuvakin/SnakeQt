#include "field.h"

Field::Field() : size(10, 10) {}

const Size Field::getSize() const {
    return this->size;
}
