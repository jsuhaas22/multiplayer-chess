chess : main.o Board.o Square.o Piece.o Pawn.o Castle.o Knight.o Bishop.o
	g++ -lsfml-graphics -lsfml-window -lsfml-system main.o Board.o Square.o Piece.o Pawn.o Castle.o Knight.o Bishop.o -o chess

main.o : main.cpp Board.hpp
	g++ -c main.cpp

Board.o : Board.cpp Board.hpp Pieces/Pawn.hpp Pieces/Castle.hpp
	g++ -c Board.cpp

Square.o : Square.cpp Square.hpp Pieces/Piece.hpp
	g++ -c Square.cpp

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

clean:
	rm chess main.o Square.o Board.o Piece.o Pawn.o Castle.o Knight.o Bishop.o
