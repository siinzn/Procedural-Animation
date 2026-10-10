#include "./segment.h"
#include <vector>
class Snake {
public:
	Snake(int segmentCount, float linkLength_);
	void update(sf::Vector2f target);
	void draw(sf::RenderWindow& window);
	~Snake() {};
private:
	std::vector<Segment> segments;
	float linkLength;
};