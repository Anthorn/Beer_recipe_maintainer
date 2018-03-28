##
# Makefile for recipeMaintainer
#

PROFILE        := NO
DEBUG          := NO
# Make TINYXML use STL
TINYXML_USE_STL := YES

CC     := gcc
CXX    := g++
LD     := g++
AR     := ar rc
RANLIB := ranlib
C11    := -std=c++11


TEST_DIR=test
CODE_DIR=./src
OBJ_DIR=$(CODE_DIR)/objs
PARSER_DIR=$(CODE_DIR)/parser

DEBUG_CFLAGS     := -Wall  -Wno-format -g -DDEBUG
RELEASE_CFLAGS   := -Wall -I$(CODE_DIR)/include -I$(PARSER_DIR)/include -I$(PARSER_DIR)/tinyxml -I$(CPPUTEST_HOME)/include ${C11} -Wno-unknown-pragmas -Wno-format -O3


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

ifeq (YES, ${TINYXML_USE_STL})
  DEFS := -DTIXML_USE_STL
else
  DEFS :=
endif

CXXFLAGS := ${CXXFLAGS} ${DEFS}

INCS := -Iinclude

#### The target of the build


OUTPUT := recipeMaintainer

all: ${OUTPUT}

#### Source files

SRCS := $(patsubst %.cc, $(CODE_DIR)/%.cc, parsable.cc beerData.cc equipment.cc fermentable.cc fermentables.cc hop.cc hops.cc style.cc water.cc waterprofile.cc yeasts.cc yeast.cc mashStep.cc mashSchedule.cc recipe.cc recipeMaintainer.cc)
OBJS := $(patsubst %.o, $(PARSER_DIR)/%.o, parser.o )
OBJS := ${OBJS} $(patsubst %.o, $(PARSER_DIR)/tinyxml/%.o, tinyxml.o tinyxmlparser.o tinyxmlerror.o tinystr.o)

OBJS := ${OBJS} $(addsuffix .o, $(basename ${SRCS}))

##### Output

${OUTPUT}: ${OBJS}
	${LD} -o $@ ${LDFLAGS} ${OBJS} ${LIBS} ${EXTRA_LIBS}

# Rules for compiling source files to object files
$(OBJ_DIR)/%.o : %.cc ${CXX} -c ${CXXFLAGS}  $< -o $@


clean:
	rm ${OBJS} ${OUTPUT}

parser.o: parser.h

test:
	make -C $(TEST_DIR)

test_clean:
	make -C $(TEST_DIR) clean
