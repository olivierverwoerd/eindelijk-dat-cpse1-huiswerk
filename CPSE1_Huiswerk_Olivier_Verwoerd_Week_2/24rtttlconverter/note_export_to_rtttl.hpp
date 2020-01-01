#include "note_player.hpp"
#include <iostream>


class note_export_to_rtttl : public note_player {
private:
 std::string filename = "melody.cpp";
public:
  note_export_to_rtttl();
  ~note_export_to_rtttl();
  void play(const note &n) override; //add the note
};