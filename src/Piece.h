#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

enum class PieceType { King, Queen, Bishop, Knight, Rook, Pawn };
enum class PieceColor { White, Black };

class Piece {	

public:
    sf::Sprite pieceSprite;
	int gridX;
	int gridY;
	PieceType type;
	PieceColor color;

    Piece(const sf::Texture& texture, PieceType type, PieceColor color, int x, int y);
};