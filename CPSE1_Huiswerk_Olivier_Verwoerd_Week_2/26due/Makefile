#############################################################################
#
# Project Makefile
#
# (c) Wouter van Ooijen (www.voti.nl) 2016
#
# This file is in the public domain.
# 
#############################################################################

# source & header files in this project (main.cpp is automatically assumed)



HEADERS += note.hpp
HEADERS += melody.hpp
SOURCES += melody.cpp
HEADERS += note_player.hpp

HEADERS += note_player_gpio.hpp
SOURCES += note_player_gpio.cpp

HEADERS += rtttl_player.hpp
SOURCES += rtttl_player.cpp

# and defer to the Makefile.due there
include maakfile
RELATIVE := $(RELATIVE)../
include $(RELATIVE)Makefile.due

