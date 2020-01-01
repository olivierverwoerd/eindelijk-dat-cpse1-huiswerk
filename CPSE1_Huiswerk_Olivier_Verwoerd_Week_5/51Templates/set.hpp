#ifndef SET_HPP
#define SET_HPP

#include <iostream>
#include "hwlib.hpp"

class set {
private:
    uint8_t iterator = 0;
    uint8_t max = 10;
    int iSet[10] = {};
    
public:
    set();
    void add( int );
    void remove( int );
    bool contains( int );
    friend std::ostream &operator<<( std::ostream & stream, const set & mSet);
};

#endif