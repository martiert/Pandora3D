# $Id: Makefile,v 1.3 2007/09/05 14:28:20 chrischu Exp $
#
# Sample Makefile for a single executable with all sources in one directory.
#
# Authors: Christopher Dyken, <erikd at ifi.uio.no>
#          Tom Fredrik Klaussen
#          Christian Schulz
#
#                   Released under the GNU PUBLIC LICENSE
#
# This Makefile finds all *.cpp source files in the current directory and
# compiles them into corresponding *.o object files. Then all these object files
# are linked to a single executable called main.
#
# The following targets are defined:
#
# - all        Builds the application. Remember to run make depend first.
#
# - depend     Scans through the source files to find the dependencies between
#              the source files.
#
# - clean      Cleans the directory, removes object files and the executable.
#
# - distclean  Cleans the directory extensively. Use this before submitting a
#              compulsory exercise.
#
#
# Some useful CXXFLAGS:
#
# -I<dir>                       Also look in <dir> for header files
# -g2                           produce debugging information
# -Wall                         turn on important warnings
# -Werror                       treat warnings as errors
# -O3                           optimize for speed
# -ffast-math                   avoids some checks in math-routines
# -fsingle-precision-constant   use float constants (instead of double)
# -pedantic                     make gcc picky
# -fprofile-arcs                Does profiling in order to optimize branching
# -fbranch-probabilities        Uses the result of profile-arcs to do the actual
#                               branch prediction
#
# Some useful LDFLAGS
#
# -l<lib>                       Link with library
# -L<dir>                       Also look in <dir> for libraries

APP      := main
CXX      := g++
LD       := g++
SOURCES  := $(wildcard *.cpp)
OBJECTS  := $(patsubst %.cpp, %.o, $(SOURCES))

CXXFLAGS := $(CXXFLAGS) -Wall -pedantic -g2 -DDEBUG -I../include
LDFLAGS  := $(LDFLAGS) -lm -lGL -L/usr/X11R6/lib -lGLU -lglut -lXi -lXmu -lcppunit

.PHONY: all depend clean

all: depend $(APP)

$(APP): $(OBJECTS)
	$(LD) -o $(APP) $(LDFLAGS) $(OBJECTS)

depend: make.dep

make.dep:
#	touch $@
#	makedepend -f$@ -- $(CXXFLAGS) -- $(SOURCES)
	for file in $(SOURCES); do $(CXX) $(CXXFLAGS) -M $$file >> $@; done

include make.dep

clean:
	rm -f *.o *.a *~ core $(APP)

distclean: clean
	rm -f make.dep *.bak
