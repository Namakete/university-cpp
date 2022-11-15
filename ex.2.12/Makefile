#!/usr/bin/make -f

CPPC := g++

STD11 := -std=c++11
STD20 := -std=c++20

TARGET_EXEC ?= a.out

TOUCH ?= touch
MKDIR_P ?= mkdir -p

TREE := tree

BUILD_DIR ?= ./build

SRC_HEADER_DIRS ?= ./src/header/
SRC_SOURCE_DIRS ?= ./src/source/
SRC_TEST_DIRS   ?= ./src/test/

SRCS := $(shell find $(SRC_SOURCE_DIRS) -name *.cpp -or -name *.c -or -name *.s )
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)
DEPS := $(OBJS:.o=.d)

$(BUILD_DIR)/$(TARGET_EXEC): $(OBJS)
	$(CPPC) $(OBJS) -o $@

$(BUILD_DIR)/%.cpp.o: %.cpp
	$(MKDIR_P) $(dir $@)
	$(CPPC) $(STD20) $(SRC_HEADER_DIRS) -c $< -o $@

run:
	cd ./build; ./a.out

.PHONY: clean
clean:
	$(RM) -rf $(BUILD_DIR) 2>/dev/null

.SILENT: create
create:
	$(MKDIR_P) $(SRC_HEADER_DIRS) $(SRC_SOURCE_DIRS) $(SRC_TEST_DIRS)
	$(TOUCH) $(SRC_SOURCE_DIRS)main.cpp
	@echo "- The structure of the created project"
	$(TREE)

-include $(DEPS)
