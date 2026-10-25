#include "../include/snake.h"

int main()
{
	sf::Vector2u WIDTH_HEIGHT = { 900, 700 };
	std::vector<float> snakeRadii = {10.0f, 15.0f, 5.0f, 15.0f, 20.0f, 20.0f, 20.0f, 15.0f, 5.0f, 5.0f, 5.0f, 5.0f, 3.0f, 3.0f, 1.0f, 1.0f, 1.0f};
	float linkLength = 35.0f;

	sf::RenderWindow window(sf::VideoMode(WIDTH_HEIGHT), "Procedural Animation");
	Snake snake(snakeRadii, linkLength);

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
