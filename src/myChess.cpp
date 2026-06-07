#include <SFML/Graphics.hpp>
#include <iostream>
#include "Piece.h"

int main()
{
	sf::RenderWindow window( sf::VideoMode( { 735, 735 } ), "myChess" );
	sf::Texture boardTexture;
	sf::Texture chessPiecesTexture;

	//load board texture from file
	if (!boardTexture.loadFromFile("../../../../assets/chessboard.jpg"))
	{
		//show error message if loading failed
		std::cerr << "Could not load 'chessboard.jpg' image!" << std::endl;
		return -1;
	}

	//load chess pieces texture from file
	if (!chessPiecesTexture.loadFromFile("../../../../assets/ChessPieces.png"))
	{
		std::cerr << "Could not load 'ChessPieces.png' image!" << std::endl;
		return -1;
	}

	sf::Sprite boardSprite(boardTexture);

	// Create chess pieces

	std::vector<Piece> pieces;

	// Create pawns

	for (int i = 0; i < 8; i++)
	{
		pieces.push_back(Piece(chessPiecesTexture,PieceType::Pawn,PieceColor::White,i,6));
		pieces.push_back(Piece(chessPiecesTexture,PieceType::Pawn,PieceColor::Black,i,1));
	}

	// Create remaining pieces

	PieceType piecesOrder[] = {PieceType::Rook, PieceType::Bishop, PieceType::Knight,
		PieceType::Queen, PieceType::King, PieceType::Knight, PieceType::Bishop, PieceType::Rook};

	for (int i = 0; i < 8; i++)
	{
		pieces.push_back(Piece(chessPiecesTexture, piecesOrder[i], PieceColor::White, i, 7));
		pieces.push_back(Piece(chessPiecesTexture, piecesOrder[i], PieceColor::Black, i, 0));
	}

	while ( window.isOpen() )
	{
		while ( const std::optional event = window.pollEvent() )
		{
			if ( event->is<sf::Event::Closed>() )
				window.close();
		}

		window.clear();
		window.draw(boardSprite);

		for (const auto& piece : pieces)
		{
			window.draw(piece.pieceSprite);
		}

		window.display();
	}
}
