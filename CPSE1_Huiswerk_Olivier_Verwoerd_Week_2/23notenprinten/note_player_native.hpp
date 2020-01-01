#include "note_player.hpp"

class note_player_native : public note_player {
public:
    note_player_native(){}
    void play (const note & n ) override;
};