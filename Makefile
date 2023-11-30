all: build/tetris

build/tetris: build/tetris.o build/iVector2.o build/tetromino.o build/gameController.o build/grid.o
	g++ build/tetris.o build/iVector2.o build/tetromino.o build/gameController.o build/grid.o -Wall -o build/tetris -I/usr/local/include -L/usr/local/lib -lraylib -lm -lpthread -ldl

build/tetris.o: src/tetris.cpp | build
	g++ -c src/tetris.cpp -o build/tetris.o

build/iVector2.o: src/iVector2.cpp src/iVector2.h
	g++ -c src/iVector2.cpp -o build/iVector2.o

build/tetromino.o: src/tetromino.cpp src/tetromino.h
	g++ -c src/tetromino.cpp -o build/tetromino.o

build/gameController.o: src/gameController.cpp src/gameController.h
	g++ -c src/gameController.cpp -o build/gameController.o

build/grid.o: src/grid.cpp src/grid.h
	g++ -c src/grid.cpp -o build/grid.o

build:
	mkdir -p build

clean:
	rm -r build
