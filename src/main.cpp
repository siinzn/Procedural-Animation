#include "../include/snake.h"

int main()
{
	sf::Vector2u WIDTH_HEIGHT = { 900, 700 };
	int snakeLength = 30;
	float linkLength = 70.0f;

	sf::RenderWindow window(sf::VideoMode(WIDTH_HEIGHT), "Procedural Animation");
	Snake snake(snakeLength, linkLength);

	while ( window.isOpen() )
	{
		while ( const std::optional event = window.pollEvent() )
		{
			if ( event->is<sf::Event::Closed>() )
				window.close();
		}

		sf::Vector2f mousePos = sf::Vector2f(sf::Mouse::getPosition(window));
		snake.update(mousePos);
		window.clear();
		snake.draw(window);
		window.display();
	}
}
