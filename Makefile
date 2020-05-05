#MakeFile!

LoadGame.o: LoadGame.cpp LoadGame.h player.h puzzle.h
	g++  -pedantic-errors -std=c++11 -c LoadGame.cpp

SaveGame.o: SaveGame.cpp SaveGame.h player.h puzzle.h
	g++  -pedantic-errors -std=c++11 -c SaveGame.cpp

main.o: main.cpp LoadGame.h SaveGame.h player.h puzzle.h
	g++  -pedantic-errors -std=c++11 -c main.cpp

main: main.o LoadGame.o SaveGame.o
	g++ main.o LoadGame.o SaveGame.o  -pedantic-errors -std=c++11 -o main

clean:
	rm -f *.o
