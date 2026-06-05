#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
	sf::RenderWindow window( sf::VideoMode( { 735, 735 } ), "SFML works!" );
	sf::Texture boardTexture;

	//Zaladuj teksturê board z pliku
	if (!boardTexture.loadFromFile("../../../../assets/chessboard.jpg"))
	{
		//wyœwietl informacje jeœli nie uda siê zadowaæ
		std::cerr << "Could not load 'chessboard.jpg' image!" << std::endl;
		return -1;
	}

	sf::Sprite boardSprite(boardTexture);

	while ( window.isOpen() )
	{
		while ( const std::optional event = window.pollEvent() )
		{
			if ( event->is<sf::Event::Closed>() )
				window.close();
		}

		window.clear();
		window.draw(boardSprite);
		window.display();
	}
}
