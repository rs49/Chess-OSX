SRC = $(wildcard src/*.cpp)

all:
	g++ $(SRC) -o chess -framework cocoa -framework SDL2 -std=c++11

