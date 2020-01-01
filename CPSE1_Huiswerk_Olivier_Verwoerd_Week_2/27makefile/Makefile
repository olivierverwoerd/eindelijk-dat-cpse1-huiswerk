#############################################################################
#
# Project Makefile
#
# (c) Wouter van Ooijen (www.voti.nl) 2016
#
# This file is in the public domain.
# 
#############################################################################

# source files in this project (main.cpp is automatically assumed)
SOURCES := converter.cpp player.cpp

# header files in this project
HEADERS := converter.hpp player.hpp

# other places to look for files for this project
SEARCH  :=

converter.cpp: Makefile convert.exe   
	convert convertme "beep.txt" > converter.cpp
	
convert.exe: convert.cpp
	g++ convert.cpp -o convert.exe


# set REATIVE to the next higher directory 
# and defer to the Makefile.due there
RELATIVE := $(RELATIVE)../
include $(RELATIVE)Makefile.due