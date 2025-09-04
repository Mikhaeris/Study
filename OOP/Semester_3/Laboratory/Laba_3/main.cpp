#include "./include/square.hpp"

#include <iostream>

void printInf(Square *ps, long double _scale);

int main() {
    Square *ps = new Square(10);
    
    for (long double scale = 0.1; scale < 1000;
        (scale < 1) ? scale += 0.1 : scale += 20) {
        ps->scale(scale);
        printInf(ps, scale);
        ps->setSide(10);
    }

    return 0;
}

void printInf(Square *ps, long double _scale) {
    std::cout << "Scale in " << _scale << "%\n";
    std::cout << "Side: " << *ps << "\n"
              << "Area: " << ps->compArea() << "\n"
              << "Perimeter: " << ps->compPerim() << "\n"
              << "Diagonal: " << ps->compDiag() << "\n" << std::endl;
}
