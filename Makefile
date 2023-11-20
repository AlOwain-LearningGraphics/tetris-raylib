all: build/tetris

build/tetris: src/tetris.cpp | build
	g++ src/*.cpp -o $@ -s -Wall -std=c++17 -I/usr/local/include -L/usr/local/lib -lraylib -lm -lpthread -ldl

build:
	mkdir -p build;

clean:
	rm -r build
