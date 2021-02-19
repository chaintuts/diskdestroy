# This file contains a make script for the DiskDestroy application
#
# Author: Josh McIntyre
#

# This block defines makefile variables
SRC_FILES=src/*.c

BUILD_DIR=bin
BUILD_BIN=diskdestroy

CC=gcc

# This rule builds the utility
build: $(SRC_FILES)
	mkdir -p $(BUILD_DIR)
	$(CC) -o $(BUILD_DIR)/$(BUILD_BIN) $(SRC_FILES)

# This rule cleans the build directory
clean: $(BUILD_DIR)
	rm $(BUILD_DIR)/* 
	rmdir $(BUILD_DIR)
