#include "set.hpp"

set::set(){}

void set::add( int number ) {
    if (iterator < max) {
        for (int i = 0; i < iterator; i++) {
            if (iSet[i] == number) {
                hwlib::cout << "ERROR. Value already in list\n";
                return;
            }
        } 
        iSet[iterator] = number;
        iterator++;
    } else {
        hwlib::cout << "ERROR the set is already full\n";
    }
}

void set::remove( int number ) {
    for (int iCheck = 0; iCheck < iterator; iCheck++) {
        if (iSet[iCheck] == number) { //number found
            for (int iRestack = iCheck; iRestack < iterator; iRestack++) {
                iSet[iRestack] = iSet[iRestack+1];
            }
            iterator--;
            break;
        }
    }
}

bool set::contains( int number ) {
    for (int i = 0; i < iterator; ++i) {
        if (iSet[i] == number) {
            return true;
        }
    }
    return false;
}

std::ostream & operator<<(std::ostream & stream, const set & mSet) {
    for (int i = 0; i < mSet.iterator; ++i) {
        stream << mSet.iSet[i] << ", ";
    }
    return stream;
}