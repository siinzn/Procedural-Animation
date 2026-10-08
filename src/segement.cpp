#include "../include/segment.h"

Segment::Segment() {};

void Segment::initSegment(float radius, float outlineThickness, sf::Color fillColor, sf::Color outlineColor, sf::Vector2f startPos) {
	segment.setRadius(radius);
	segment.setOrigin({ radius, radius });
	segment.setOutlineThickness(outlineThickness);
	segment.setFillColor(fillColor);
	segment.setOutlineColor(outlineColor);
	segment.setPosition(startPos);
}

sf::Vector2f Segment::getPos() {
	return segment.getPosition();
}

void Segment::constraintDistance(sf::Vector2f anchorPosition, float constraintLength) {
	sf::Vector2f segmentPos = segment.getPosition();
	sf::Vector2f arrowDir = segmentPos - anchorPosition;
	if (arrowDir.x == 0 && arrowDir.y == 0) return; // normalized() function doesnt work for zero vectors since length becomes 0
	sf::Vector2f nArrowDir = arrowDir.normalized();
	sf::Vector2f newPointPos = sf::Vector2f(anchorPosition) + nArrowDir * constraintLength;
	segment.setPosition(newPointPos);
}

void Segment::drawSegment(sf::RenderWindow& window) {
	window.draw(segment);
}