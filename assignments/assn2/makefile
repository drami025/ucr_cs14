all: main.o WordLadder.o stack.o queue.o
	g++ -W -Wall -Werror -ansi -pedantic main.o WordLadder.o -o main.out
	
main.o: main.cc
	g++ -W -Wall -Werror -ansi -pedantic -c main.cc
	
WordLadder.o: WordLadder.cc WordLadder.h stack.h queue.h
	g++ -W -Wall -Werror -ansi -pedantic -c WordLadder.cc WordLadder.h stack.h queue.h
	

	