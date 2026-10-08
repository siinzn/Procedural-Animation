#include "../include/segment.h"

int main()
{
	sf::RenderWindow window( sf::VideoMode( { 900, 700 } ), "Procedural Animation" );
	Segment head;
	Segment body1;
	Segment body2;
	Segment body3;
	Segment body4;

	head.initSegment(20.0f, 5.0f, sf::Color::Transparent, sf::Color::Yellow, { 450.f, 350.f });
	body1.initSegment(20.0f, 5.0f, sf::Color::Transparent, sf::Color::Red, { 450.f, 350.f });
	body2.initSegment(40.0f, 5.0f, sf::Color::Transparent, sf::Color::Red, { 450.f, 350.f });
	body3.initSegment(40.0f, 5.0f, sf::Color::Transparent, sf::Color::Red, { 450.f, 350.f });
	body4.initSegment(15.0f, 5.0f, sf::Color::Transparent, sf::Color::Red, { 450.f, 350.f });
	
	while ( window.isOpen() )
	{
		while ( const std::optional event = window.pollEvent() )
		{
			if ( event->is<sf::Event::Closed>() )
				window.close();
		}

		sf::Vector2f mousePos = sf::Vector2f(sf::Mouse::getPosition(window));
		head.constraintDistance(mousePos, 10.0f);
		body1.constraintDistance(head.getPos(), 70.0f);
		body2.constraintDistance(body1.getPos(), 70.0f);
		body3.constraintDistance(body2.getPos(), 70.0f);
		body4.constraintDistance(body3.getPos(), 70.0f);

		window.clear();
		head.drawSegment(window);
		body1.drawSegment(window);
		body2.drawSegment(window);
		body3.drawSegment(window);
		body4.drawSegment(window);
		window.display();
	}
}
