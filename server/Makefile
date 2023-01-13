server : main.o Server.o
	g++ -lsfml-network -lsfml-system main.o Server.o -o server

main.o : main.cpp Server.hpp
	g++ -c main.cpp

Server.o : Server.cpp Server.hpp
	g++ -c Server.cpp

clean:
	rm server main.o Server.o