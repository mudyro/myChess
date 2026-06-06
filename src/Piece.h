#pragma once
#include <iostream>

class Piece {
public:
    sf::Sprite pieceSprite;
    Piece(const sf::Texture& texture);
};