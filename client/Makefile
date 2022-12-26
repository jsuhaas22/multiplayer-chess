chess : main.o Square.o
	g++ -lsfml-graphics -lsfml-window -lsfml-system main.o Square.o -o chess

main.o : main.cpp Square.hpp
	g++ -c main.cpp

Square.o : Square.cpp Square.hpp
	g++ -c Square.cpp

clean:
	rm chess main.o Square.o