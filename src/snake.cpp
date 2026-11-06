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
			bend(i);
		}
		targetPos = segments[i].getPos();
	}
}

void Snake::bend(size_t i) {
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

void Snake::parametric_eq() {
	leftPoints.clear();
	rightPoints.clear();
	float angle = 0.0;
	for (size_t i = 0; i < segments.size(); i++) {
		sf::Vector2f current = segments[i].getPos();
		
		if (i > 0) {
			sf::Vector2f ahead = segments[i - 1].getPos();
			sf::Vector2f heading = ahead - current;
			angle = atan2(heading.y, heading.x);
		}
		else if (i == 0) {
			sf::Vector2f heading = current - segments[1].getPos();
			angle = atan2(heading.y, heading.x);
		}
		sf::Vector2f left = current + sf::Vector2f(cos(angle + (pi / 2)), sin(angle + (pi / 2))) * segments[i].getRadii();
		sf::Vector2f right = current + sf::Vector2f(cos(angle - (pi / 2)), sin(angle - (pi / 2))) * segments[i].getRadii();
		leftPoints.push_back(left);
		rightPoints.push_back(right);
	}
}

void Snake::draw(sf::RenderWindow& window) {
	for (auto& s : segments) {
		s.drawSegment(window);
	}
	sf::VertexArray leftPoints_(sf::PrimitiveType::Points, leftPoints.size());
	sf::VertexArray rightPoints_(sf::PrimitiveType::Points, leftPoints.size());
	for (size_t i{ 0 }; i < leftPoints.size(); i++) {
		leftPoints_[i].position = leftPoints[i];
	}
	for (size_t i{ 0 }; i < rightPoints.size(); i++) {
		rightPoints_[i].position = rightPoints[i];
	}
	window.draw(leftPoints_);
	window.draw(rightPoints_);
}