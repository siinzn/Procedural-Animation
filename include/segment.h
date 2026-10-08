#include "SFML/Graphics.hpp"

class Segment {
public:
	Segment();
	void initSegment(float radius, float outlineThickness, sf::Color fillColor, sf::Color outlineColor, sf::Vector2f startPos);
	void constraintDistance(sf::Vector2f anchorPosition, float constraintLength);
	void drawSegment(sf::RenderWindow& window);
	sf::Vector2f getPos();
	~Segment() {};
private:
	sf::CircleShape segment;
};