#ifndef SQUARE_H
#define SQUARE_H

#include <iostream>

class Square {
public:
    /* constructors */
    Square();
    Square(long double _side);

    /* destructor */
    ~Square();

    /* getters setters */
    int getSide();
    void setSide(long double _side);
    
    /* additional finctions */
    void scale(long double _percent);
    long double compArea();
    long double compPerim();
    long double compDiag();
    
    /* overload operators */
    friend std::ostream& operator<<(std::ostream& _out, const Square& _square);
     
private:
    long double side;
};

#endif
