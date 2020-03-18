CC=g++
CFLAGS=-Wall
SRC_DIR=src
BUILD_DIR=build
TARGET=$(BUILD_DIR)/curry

SRC=$(wildcard $(SRC_DIR)/*.cpp)

all: $(TARGET)

$(TARGET) : $(SRC)
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -o $@ $^
