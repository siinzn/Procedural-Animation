#include "../include/snake.h"

std::vector<float> radiiValues() {
    std::vector<float> values;
    const int num_points = 70;
    values.reserve(num_points);
    const float PI = 3.14159265358979323846f;

    for (int i = 0; i < num_points; ++i) {
        // Normalize t to a 0.0 to 1.0 range
        float t = static_cast<float>(i) / (num_points - 1);
        // 1. Base line sloping from 15.0f down to 8.0f
        float linear_part = 15.0f * (1.0f - t) + 2.0f * t;
        // 2. Sine wave bump
        float sine_part = 20.0f * std::sin(t * PI);
        values.push_back(linear_part + sine_part);
    }
    return values;
}

int main()
{
	sf::Vector2u WIDTH_HEIGHT = { 900, 700 };
	std::vector<float> snakeRadii = radiiValues();
	float linkLength = 15.0f;

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
		snake.parametric_eq();
		window.clear();
		snake.draw(window);
		window.display();
	}
}
