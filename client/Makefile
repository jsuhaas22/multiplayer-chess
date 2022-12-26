chess : main.o Board.o Square.o
	g++ -lsfml-graphics -lsfml-window -lsfml-system main.o Board.o Square.o -o chess

main.o : main.cpp Board.hpp
	g++ -c main.cpp

Board.o : Board.cpp Board.hpp
	g++ -c Board.cpp

Square.o : Square.cpp Square.hpp
	g++ -c Square.cpp

clean:
	rm chess main.o Square.o
