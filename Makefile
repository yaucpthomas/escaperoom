#MakeFile!

LoadGame.o: LoadGame.cpp LoadGame.h
		g++ -c LoadGame.cpp

main.o: main.cpp LoadGame.h player.h
		g++ -c main.cpp

main: main.o LoadGame.o
	g++ main.o LoadGame.o -o main
