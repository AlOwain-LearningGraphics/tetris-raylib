all: build/tetris

build/tetris: build/tetris.o build/sVector2.o build/tetromino.o
	g++ build/tetris.o build/sVector2.o build/tetromino.o -Wall -o build/tetris -I/usr/local/include -L/usr/local/lib -lraylib -lm -lpthread -ldl

build/tetris.o: src/tetris.cpp | build
	g++ -c src/tetris.cpp -o build/tetris.o

build/sVector2.o: src/sVector2.cpp src/sVector2.h
	g++ -c src/sVector2.cpp -o build/sVector2.o

build/tetromino.o: src/tetromino.cpp src/tetromino.h
	g++ -c src/tetromino.cpp -o build/tetromino.o

build:
	mkdir -p build

clean:
	rm -r build
