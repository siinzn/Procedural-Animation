#include "../include/snake.h"

Snake::Snake(int segmentCount, float linkLength_) : linkLength(linkLength_) {
	for (int i = 0; i < segmentCount; i++) {
		segments.push_back(Segment());
		if (i == 0) {
			segments[i].initSegment(10.0f, 5.0f, sf::Color::Transparent, sf::Color::Magenta, { 450.f, 350.f }); // head
		} else {
			segments[i].initSegment(20.0f, 5.0f, sf::Color::Transparent, sf::Color::Yellow, { 450.f, 350.f }); // body
		}
	}
}

void Snake::update(sf::Vector2f target) {
	for (int i = 0; i < segments.size();i++) {
		segments[i].constraintDistance(target, linkLength);
		target = segments[i].getPos();
	}
}

void Snake::draw(sf::RenderWindow& window) {
	for (auto& s : segments) {
		s.drawSegment(window);
	}
}