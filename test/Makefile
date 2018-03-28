CPPUTEST_HOME := /home/anton/cpputest

PROJECT_DIR := home/anton/Documents/projects/Beer_recipe_maintainer
#SRC_DIR=$(PROJECT_DIR)/src
#TEST_DIR := $(PROJECT_DIR)/test
# specify where the source code and includes are located
#INCLUDE_DIRS=$(SRC_DIR)
#SRC_DIRS=$(SRC_DIR)
#
# # specify where the test code is located
TEST_SRC_DIRS := $(TEST_DIR)
TEST_SRC_FILES := main.cpp test.cpp
#CPPUTEST_OBJS_DIR := .

CPPUTEST_USE_MEM_LEAK_DETECTION := N

TEST_TARGET=example

#CPPUTEST_USE_EXTENSIONS = Y
#CPP_PLATFORM = Gcc

TEST_SRC_DIRS = \
	test
SRC_DIRS = \
	src
#CPPUTEST_USE_EXTENSIONS = Y

INCLUDE_DIRS =\
  .\
  src\
  $(CPPUTEST_HOME)/include\

CPPFLAGS += -I$(CPPUTEST_HOME)/include

LD_LIBRARIES = -L$(CPPUTEST_HOME)/lib -lCppUTest -lCppUTestExt


include $(CPPUTEST_HOME)/build/MakefileWorker.mk
