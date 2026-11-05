#include "./segment.h"
#include <vector>
#include <cmath>
#include <numbers>

class Snake {
public:
	Snake(std::vector<float> egmentCount, float linkLength_);
	void update(sf::Vector2f target);
	void draw(sf::RenderWindow& window);
	void bend(std::vector<Segment> segment, size_t i);
	~Snake() {};
private:
	std::vector<Segment> segments;
	float linkLength;
	float maxBend = 0.8; // this is in radians
	float pi = 2 * acos(0.0);
};