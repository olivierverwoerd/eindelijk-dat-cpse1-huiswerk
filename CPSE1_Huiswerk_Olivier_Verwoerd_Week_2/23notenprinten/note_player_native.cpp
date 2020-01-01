#include <iostream>
#include "note_player_native.hpp"

void note_player_native::play(const note & n){
    std::cout << "Frequency: " << n.frequency << " Duration: " << n.duration << "\n";
}