#include "../include/square.hpp"
#include <cmath>

/* constructors*/
Square::Square() {}

Square::Square(long double _side) {
    side = _side;
}

/* destructors */
Square::~Square() {}

/* getters setters */
int Square::getSide() {
    return side;
}
void Square::setSide(long double _side) { 
    if (_side > 0) {
        side = _side;
    } else {
        std::cout << "error: negative _side" << std::endl;
    }
}

/* additional finctions */
void Square::scale(long double _percent) {
    if (_percent > 0) {
        side += side * (_percent/100);
    } else {
        std::cout << "error: negative _percent" << std::endl;
    }
}

long double Square::compArea() {
    return side*side;
}

long double Square::compPerim() {
    return side*4;
}

long double Square::compDiag() {
    return side*sqrt(2);
}

/* overload operators */
std::ostream& operator<<(std::ostream& _out, const Square& _square) {
    return _out << _square.side;
}
