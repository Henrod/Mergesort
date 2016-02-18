CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra

OBJ_FILE = obj/main.o
HPP_PATH = hdr
CPP_FILES = $(wildcard src/*.cpp)

all:
	$(CXX) $(CXXFLAGS) -I$(HPP_PATH) $(CPP_FILES) -o$(OBJ_FILE)

clean:
	rm -rf $(OBJ_FILE)
