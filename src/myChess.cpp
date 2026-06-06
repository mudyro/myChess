#include <SFML/Graphics.hpp>
#include <iostream>
#include "piece.h"

int main()
{
	sf::RenderWindow window( sf::VideoMode( { 735, 735 } ), "SFML works!" );
	sf::Texture boardTexture;
	sf::Texture chessPiecesTexture;

	//Zaladuj tekstur� board z pliku
	if (!boardTexture.loadFromFile("../../../../assets/chessboard.jpg"))
	{
		//wy�wietl informacje je�li nie uda si� zadowa�
		std::cerr << "Could not load 'chessboard.jpg' image!" << std::endl;
		return -1;
	}

	//Zaladuj tekstur� figur
	if (!chessPiecesTexture.loadFromFile("../../../../assets/ChessPieces.png"))
	{
		std::cerr << "Could not load 'ChessPieces.png' image!" << std::endl;
		return -1;
	}

	sf::Sprite boardSprite(boardTexture);

	Piece whiteKing(chessPiecesTexture);
	whiteKing.pieceSprite.setTextureRect(sf::IntRect({ 0,0 }, { 213,213 }));

	while ( window.isOpen() )
	{
		while ( const std::optional event = window.pollEvent() )
		{
			if ( event->is<sf::Event::Closed>() )
				window.close();
		}

		window.clear();
		window.draw(boardSprite);
		window.draw(whiteKing.pieceSprite);
		window.display();
	}
}
