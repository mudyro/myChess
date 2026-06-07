#include <SFML/Graphics.hpp>
#include <iostream>
#include "Piece.h"

Piece::Piece(const sf::Texture& texture, PieceType type, PieceColor color, int x, int y) : pieceSprite(texture), type(type), color(color), gridX(x), gridY(y) 
{
	// Set the texture rectangle for the piece based on its type and color

	int size = 213; // each piece is ~213x213 pixels in the texture
	int textureStartX = static_cast<int> (type) * size;
	int textureStartY = (color == PieceColor::Black) ? size : 0; // black pieces are in the second row of the texture
	
	pieceSprite.setTextureRect(sf::IntRect({ textureStartX,textureStartY }, { size, size }));
	
	//Scale and move each piece to fit the chessboard 

	float targetSize = 83.0f;
	float scaleFactor = targetSize / size;

	pieceSprite.setScale({ scaleFactor, scaleFactor });

	float possitionOffset = 37.0f; // offset to center the piece in the square
	
	pieceSprite.setPosition({ x * targetSize + possitionOffset, y * targetSize + possitionOffset });
}