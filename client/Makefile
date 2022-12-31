chess : main.o Board.o Square.o Game.o Piece.o Pawn.o Castle.o Knight.o Bishop.o Queen.o King.o
	g++ -lsfml-graphics -lsfml-window -lsfml-system main.o Board.o Square.o Game.o Piece.o Pawn.o Castle.o Knight.o Bishop.o Queen.o King.o -o chess

main.o : main.cpp Board.hpp
	g++ -c main.cpp

Board.o : Board.cpp Board.hpp Pieces/Pawn.hpp Pieces/Castle.hpp
	g++ -c Board.cpp

Square.o : Square.cpp Square.hpp Pieces/Piece.hpp
	g++ -c Square.cpp

Game.o : Game.cpp Game.hpp
	g++ -c Game.cpp

Piece.o : Pieces/Piece.cpp Pieces/Piece.hpp
	g++ -c Pieces/Piece.cpp

Pawn.o : Pieces/Pawn.cpp Pieces/Pawn.hpp
	g++ -c Pieces/Pawn.cpp

Castle.o : Pieces/Castle.cpp Pieces/Castle.hpp
	g++ -c Pieces/Castle.cpp

Knight.o : Pieces/Knight.cpp Pieces/Knight.hpp
	g++ -c Pieces/Knight.cpp

Bishop.o : Pieces/Bishop.cpp Pieces/Bishop.hpp
	g++ -c Pieces/Bishop.cpp

Queen.o : Pieces/Queen.cpp Pieces/Queen.hpp
	g++ -c Pieces/Queen.cpp

King.o : Pieces/King.cpp Pieces/King.hpp
	g++ -c Pieces/King.cpp

clean:
	rm chess main.o Square.o Board.o Game.o Piece.o Pawn.o Castle.o Knight.o Bishop.o Queen.o King.o
