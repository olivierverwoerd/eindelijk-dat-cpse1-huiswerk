#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <iostream>
#include "set.hpp"


TEST_CASE( "Set add" ){
    auto s = set();
    for (int i = 1; i < 20; i++) {
        s.add(i);
    }
    REQUIRE( s.contains(2) == true ); 
    REQUIRE( s.contains(12) == false ); 
}

TEST_CASE( "Set remove" ){
    auto s = set();
    s.add(3);
    s.add(4);
    s.remove(3);
    s.remove(1);
    REQUIRE( s.contains(3) == false );
    REQUIRE( s.contains(4) == true );
}

/*
int main( void ) {
    auto s = set();
    for (int i = 1; i < 12; i++) {
        s.add(i);
    }
    std::cout << s << std::endl;

    s.remove(4);
    s.remove(6);

    std::cout << s << std::endl;
    std::cout << s.contains(9) << std::endl;
    std::cout << s.contains(4) << std::endl;
    return 0;
}
*/