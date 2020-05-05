#MakeFile!

LoadGame.o: LoadGame.cpp LoadGame.h player.h puzzle.h
		g++ -c LoadGame.cpp

main.o: main.cpp LoadGame.h player.h puzzle.h
		g++ -c main.cpp

main: main.o LoadGame.o
	g++ main.o LoadGame.o -o main

clean:
	rm -f *.o
