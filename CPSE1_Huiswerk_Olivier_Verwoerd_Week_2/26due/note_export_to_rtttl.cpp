#include "note_export_to_rtttl.hpp"
#include <fstream>
#include <iostream>

note_export_to_rtttl::note_export_to_rtttl() {
  std::ofstream file;
  file.open(filename);
  file << "#ifndef SONG_HPP\n"
  << "#define SONG_HPP\n\n"
  << "#include \"melody.hpp\"\n\n"
  << "class song : public melody {\n"
  << "public:\n"
  << "    void play( note_player & p ){\n";
  file.close();
}

void note_export_to_rtttl::play(const note &n) {
  std::ofstream file;
  file.open(filename, std::ofstream::app);
  file << "        p.play( note{ "
  << n.frequency 
  << ", "
  << n.duration
  << " } );\n";
}

note_export_to_rtttl::~note_export_to_rtttl() {
  std::ofstream file;
  file.open(filename, std::ofstream::app);
  file << "    }\n"
  << "};\n\n"
  << "#endif";
  file.close();
  std::cout << "File Exported\n";
  }