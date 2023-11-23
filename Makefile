all: build/tetris

build/tetris: build/tetris.o
	g++ build/tetris.o build/iVector2.o -Wall -o build/tetris -I/usr/local/include -L/usr/local/lib -lraylib -lm -lpthread -ldl

build/tetris.o: src/tetris.cpp | build
	g++ -c src/tetris.cpp -o build/tetris.o

build/iVector2.o: src/iVector2.cpp
	g++ -c src/iVector2.cpp -o build/iVector2.o
build:
	mkdir -p build

clean:
	rm -r build
