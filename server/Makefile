server : main.o Server.o Message.o
	g++ -lsfml-network -lsfml-system main.o Server.o Message.o -o server

main.o : main.cpp Server.hpp
	g++ -c main.cpp

Server.o : Server.cpp Server.hpp ../Message.hpp
	g++ -c Server.cpp

Message.o : ../Message.cpp ../Message.hpp
	g++ -c ../Message.cpp

clean:
	rm server main.o Server.o Message.o