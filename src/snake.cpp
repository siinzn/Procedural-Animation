#include "../include/snake.h"

Snake::Snake(std::vector<float>segmentCount, float linkLength_) : linkLength(linkLength_) {
	for (size_t i = 0; i < segmentCount.size(); i++) {
		segments.push_back(Segment());
		segments[i].initSegment(segmentCount[i], 5.0f, sf::Color::Transparent, sf::Color::Magenta, {450.f, 350.f}); // head
	}
}

void Snake::update(sf::Vector2f targetPos) {
	for (size_t i = 0; i < segments.size();i++) {
		segments[i].constraintDistance(targetPos, linkLength);
		if (i >= 2) {
			bend(segments, i);
		}
		targetPos = segments[i].getPos();
	}
}

void Snake::bend(std::vector<Segment>segment, size_t i) {
	// get position of 2 segment before segment[i]
	sf::Vector2f aPos = segments[i - 2].getPos();
	// get position of 1 segment before segment[i]
	sf::Vector2f bPos = segments[i - 1].getPos();
	sf::Vector2f cPos = segments[i].getPos();
	// get dir directions fro b-a and c-b
	sf::Vector2f baDirection = bPos - aPos;
	sf::Vector2f cbDirection = cPos - bPos;

	// get the angle but in radians
	float prevAngle = atan2(baDirection.y, baDirection.x);
	float afterAngle = atan2(cbDirection.y, cbDirection.x);
	//this is how much difference there is between those two angles
	float bend = afterAngle - prevAngle;

	// check if the bend is outside of -pi or pi
	if (bend > pi) bend -= 2 * pi;
	else if (bend < -pi) bend += 2 * pi;

	//check if the bend is more than maxBend
	if (bend > maxBend) bend = maxBend;
	else if (bend < -maxBend) bend = (-maxBend);

	float finalAngle = prevAngle + bend;
	sf::Vector2f newCPos = bPos + sf::Vector2f(cos(finalAngle), sin(finalAngle)) * linkLength;
	segments[i].setPos(newCPos);
}

void Snake::draw(sf::RenderWindow& window) {
	for (auto& s : segments) {
		s.drawSegment(window);
	}
}