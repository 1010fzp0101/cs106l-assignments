#include "class.h"
bool Circle::isValidRadius(int radius) {
    return radius >= 0;
}

int Circle::getData() const {
    return this->data;
}

void Circle::setData(int radius) {
    if (isValidRadius(radius)) {
        this->data = radius;
    }
}