#include "Collider.h"

Collider::Collider(sf::RectangleShape* collider) : collider(collider)
{
}

Collider::~Collider()
{
}

bool Collider::CheckCollision(Collider* other, float push, sf::Vector2f otherPos) {

	sf::Vector2f oP = otherPos, oHS = other->getHalfSize();
	sf::Vector2f tP = getPos(), tHS = getHalfSize();

	float dtX = oP.x + oHS.x - tP.x - tHS.x;
	float dtY = oP.y + oHS.y - tP.y - tHS.x;
	float intersectX = abs(dtX) - (oHS.x + tHS.x);
	float intersectY = abs(dtY) - (oHS.y + tHS.y);

	if (intersectX < 0.0f && intersectY < 0.0f) {
		push = std::min(std::max(push, 0.0f), 1.0f);

		if (intersectX > intersectY) {
			if (dtX > 0) {
				Move(intersectX * (1 - push), 0);
				other->Move(-intersectX * push, 0);
			}
			else {
				Move(-intersectX * (1 - push), 0);
				other->Move(intersectX * push, 0);
			}
		}
		else {
			if (dtY > 0) {
				Move(0, intersectY * (1 - push));
				other->Move(0, -intersectY * push);
			}
			else {
				Move(0, -intersectY * (1 - push));
				other->Move(0, intersectY * push);
			}
		}

		return true;
	}

	return false;
}

bool Collider::CheckCollision(Collider* other, float push) {
	sf::Vector2f oP = other->getPos(), oHS = other->getHalfSize();
	sf::Vector2f tP = getPos(), tHS = getHalfSize();

	float dtX = oP.x + oHS.x - tP.x - tHS.x; 
	float dtY = oP.y + oHS.y - tP.y - tHS.x; 
	float intersectX = abs(dtX) - (oHS.x + tHS.x);
	float intersectY = abs(dtY) - (oHS.y + tHS.y); 

	if (intersectX < 0.0f && intersectY < 0.0f) {
		push = std::min(std::max(push,0.0f), 1.0f);

		if (intersectX > intersectY) {
			if (dtX > 0) {
				Move(intersectX * (1 - push), 0);
				other->Move(-intersectX * push, 0);
			}
			else {
				Move(-intersectX * (1 - push), 0);
				other->Move(intersectX * push, 0);
			}
		}
		else {
			if (dtY > 0) {
				Move(0, intersectY * (1 - push));
				other->Move(0, -intersectY * push);
			}
			else {
				Move(0, -intersectY * (1 - push));
				other->Move(0, intersectY * push);
			}
		}

		return true;
	}

	return false;
}