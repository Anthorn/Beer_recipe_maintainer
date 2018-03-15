##
# Makefile for recipeMaintainer
#

PROFILE        := NO
DEBUG          := NO
# Make TINYXML use STL

CC     := gcc
CXX    := g++
LD     := g++
AR     := ar rc
RANLIB := ranlib

DEBUG_CFLAGS     := -Wall  -Wno-format -g -DDEBUG
RELEASE_CFLAGS   := -Wall -Iinclude -Iparser/include -Iparser/tinyxml -Wno-unknown-pragmas -Wno-format -O3

LIBS		 :=

DEBUG_CXXFLAGS   := ${DEBUG_CFLAGS}
RELEASE_CXXFLAGS := ${RELEASE_CFLAGS}

DEBUG_LDFLAGS    := -g
RELEASE_LDFLAGS  :=

ifeq (YES, ${DEBUG})
   CFLAGS       := ${DEBUG_CFLAGS}
   CXXFLAGS     := ${DEBUG_CXXFLAGS}
   LDFLAGS      := ${DEBUG_LDFLAGS}
else
   CFLAGS       := ${RELEASE_CFLAGS}
   CXXFLAGS     := ${RELEASE_CXXFLAGS}
   LDFLAGS      := ${RELEASE_LDFLAGS}
endif

ifeq (YES, ${PROFILE})
   CFLAGS   := ${CFLAGS} -pg -O3
   CXXFLAGS := ${CXXFLAGS} -pg -O3
   LDFLAGS  := ${LDFLAGS} -pg
endif

INCS := -Iinclude

#### The target of the build

OUTPUT := recipeMaintainer

all: ${OUTPUT}

#### Source files

SRCS := equipment.cc fermentable.cc hop.cc  style.cc water.cc yeast.cc mashStep.cc \
	 recipe.cc recipeMaintainer.cc
#OBJS := $(patsubst %.o, tinyxml/%.o, tinyxml.o tinyxmlparser.o tinyxmlerror.o tinystr.o)

OBJS := $(addsuffix .o, $(basename ${SRCS}))

##### Output

${OUTPUT}: ${OBJS}
	${LD} -o $@ ${LDFLAGS} ${OBJS} ${LIBS} ${EXTRA_LIBS}

# Rules for compiling source files to object files
%.o : %.cc ${CXX} -c ${CXXFLAGS} $< -o $@


clean:
	rm ${OBJS} ${OUTPUT}

parser.o: parser.h
