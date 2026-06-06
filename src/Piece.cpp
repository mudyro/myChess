#include <SFML/Graphics.hpp>
#include <iostream>
#include "piece.h"

Piece::Piece(const sf::Texture& texture) {
    pieceSprite.setTexture(texture);
};