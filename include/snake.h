#include "./segment.h"
#include <vector>
#include <cmath>
#include <numbers>

class Snake {
public:
	Snake(std::vector<float> egmentCount, float linkLength_);
	void update(sf::Vector2f target);
	void draw(sf::RenderWindow& window);
	~Snake() {};
private:
	std::vector<Segment> segments;
	float linkLength;
};