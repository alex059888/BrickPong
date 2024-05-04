#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
using namespace std;

class Collider
{
public:
	Collider(sf::RectangleShape* collider);
	~Collider();
	bool CheckCollision(Collider* other, float push);
	bool CheckCollision(Collider* other, float push, sf::Vector2f otherPos);
	void Move(float dx, float dy) { collider->move(dx, dy); }
	sf::Vector2f getPos() { return collider->getPosition(); }
	sf::Vector2f getHalfSize() { return collider->getSize() / 2.0f; }

private:
	sf::RectangleShape* collider;
};
