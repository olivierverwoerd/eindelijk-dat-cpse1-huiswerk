#ifndef SONG_HPP
#define SONG_HPP

#include "melody.hpp"

class song : public melody {
public:
    void play( note_player & p ){
        p.play( note{ 523, 125000 } );
        p.play( note{ 587, 125000 } );
        p.play( note{ 698, 125000 } );
        p.play( note{ 587, 125000 } );
        p.play( note{ 880, 125000 } );
        p.play( note{ 0, 125000 } );
        p.play( note{ 0, 62500 } );
        p.play( note{ 880, 250000 } );
        p.play( note{ 0, 125000 } );
        p.play( note{ 784, 500000 } );
        p.play( note{ 523, 125000 } );
        p.play( note{ 587, 125000 } );
        p.play( note{ 698, 125000 } );
        p.play( note{ 587, 125000 } );
        p.play( note{ 784, 125000 } );
        p.play( note{ 0, 125000 } );
        p.play( note{ 0, 62500 } );
        p.play( note{ 784, 250000 } );
        p.play( note{ 0, 125000 } );
        p.play( note{ 698, 250000 } );
        p.play( note{ 659, 125000 } );
        p.play( note{ 587, 250000 } );
        p.play( note{ 523, 125000 } );
        p.play( note{ 587, 125000 } );
        p.play( note{ 698, 125000 } );
        p.play( note{ 587, 125000 } );
        p.play( note{ 698, 500000 } );
        p.play( note{ 784, 250000 } );
        p.play( note{ 659, 250000 } );
        p.play( note{ 587, 125000 } );
        p.play( note{ 523, 250000 } );
        p.play( note{ 261, 250000 } );
        p.play( note{ 523, 250000 } );
        p.play( note{ 784, 250000 } );
        p.play( note{ 0, 250000 } );
        p.play( note{ 698, 1000000 } );
        p.play( note{ 523, 125000 } );
        p.play( note{ 587, 125000 } );
        p.play( note{ 698, 125000 } );
        p.play( note{ 587, 125000 } );
        p.play( note{ 880, 125000 } );
        p.play( note{ 0, 125000 } );
        p.play( note{ 0, 62500 } );
        p.play( note{ 880, 250000 } );
        p.play( note{ 0, 125000 } );
        p.play( note{ 784, 500000 } );
        p.play( note{ 523, 125000 } );
        p.play( note{ 587, 125000 } );
        p.play( note{ 698, 125000 } );
        p.play( note{ 587, 125000 } );
        p.play( note{ 1046, 500000 } );
        p.play( note{ 659, 250000 } );
        p.play( note{ 698, 250000 } );
        p.play( note{ 659, 125000 } );
        p.play( note{ 587, 250000 } );
        p.play( note{ 523, 125000 } );
        p.play( note{ 587, 125000 } );
        p.play( note{ 698, 125000 } );
        p.play( note{ 587, 125000 } );
        p.play( note{ 698, 500000 } );
        p.play( note{ 784, 250000 } );
        p.play( note{ 659, 250000 } );
        p.play( note{ 587, 125000 } );
        p.play( note{ 523, 250000 } );
        p.play( note{ 261, 250000 } );
        p.play( note{ 523, 250000 } );
        p.play( note{ 784, 250000 } );
        p.play( note{ 0, 250000 } );
        p.play( note{ 698, 1000000 } );
    }
};

#endif