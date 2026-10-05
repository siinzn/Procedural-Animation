#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window( sf::VideoMode( { 900, 700 } ), "SFML works!" );
	sf::CircleShape point( 10.f );
	sf::CircleShape anchor(10.f);
	sf::Vector2f pointPos = { 0.0f, 0.0f };
	point.setFillColor( sf::Color::Transparent );
	anchor.setFillColor(sf::Color::Transparent);

	point.setOutlineThickness(5.f);
	point.setOutlineColor(sf::Color::Blue);
	anchor.setOutlineThickness(10.f);
	anchor.setOutlineColor(sf::Color::White);

	while ( window.isOpen() )
	{
		while ( const std::optional event = window.pollEvent() )
		{
			if ( event->is<sf::Event::Closed>() )
				window.close();
		}
		sf::Vector2i mousePos = sf::Mouse::getPosition(window);

		anchor.setPosition(sf::Vector2f(mousePos));
		sf::Vector2f arrowDir = pointPos - sf::Vector2f(mousePos);

		if (arrowDir.x == 0 && arrowDir.y == 0) break; // normalized() function doesnt work for zero vectors since length becomes 0

		sf::Vector2f nArrowDir = arrowDir.normalized();
		sf::Vector2f newPointPos = sf::Vector2f(mousePos) + nArrowDir * 100.0f;

		point.setPosition(newPointPos);

		window.clear();
		window.draw(point);
		window.draw(anchor);
		window.display();
	}
}
