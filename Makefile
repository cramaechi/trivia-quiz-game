trivia: main.o trivia.o
	g++ main.o trivia.o -o trivia

main.o: main.cpp
	g++ -c main.cpp

trivia.o: trivia.cpp trivia.h
	g++ -c trivia.cpp

clean:
	rm *.o trivia
