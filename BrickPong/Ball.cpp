#include "Ball.h"

namespace ball {
	Ball::Ball(sf::Vector2f pos, sf::Texture* ballTex)
	{
		Ball::pos = pos;
		Ball::ballTex = ballTex;
		colX = 8;
		colY = 8;
		mesh.setSize(sf::Vector2f(2 * colX, 2 * colY));
		mesh.setFillColor(sf::Color(255, 255, 255, 255));
		mesh.setTexture(ballTex);
		dir = sf::Vector2f(1,1);
		speed = 5;
	}

	Ball::~Ball()
	{
	}

	bool Ball::isBoxVisibleAt(sf::Vector2i pos, br::Brick** bricks) {
		if (pos.x < 0 || pos.y < 0 || pos.x >= 16 || pos.y >= 24) return 0;
		return bricks[pos.x][pos.y].isVisible();
	}

	void Ball::tick(float dt, br::Brick** bricks, lp::LeftPlayer* leftP, rp::RightPlayer* rightP) {
		sf::Vector2f fP = pos + dir * dt * speed; //future pos
		//coll
		for (int i = 0; i < 16; i++)
			for (int j = 0; j < 24; j++) {
				if (isBoxVisibleAt(sf::Vector2i(i, j), bricks))
					if (getCollider()->CheckCollision(bricks[i][j].getCollider(), 0, sf::Vector2f(i * 64.0f, j * 32.0f))) {
						float dtX = pos.x - i * 64 + 32;
						float dtY = pos.y - j * 32 + 16;
						float intersectX = abs(dtX) - (32 + 8);
						float intersectY = abs(dtY) - (16 + 8);
						if (intersectX < intersectY) {
							if (intersectX < 0) dir.x = -1;
							if (intersectX > 0) dir.x = 1;
						}
						else {
							if (intersectY < 0) dir.y = -1;
							if (intersectY > 0) dir.y = 1;
						}
						bricks[i][j].shatter();
					}
			}
		//coll
		if (pos.y - colY < 0) dir.y = 1;
		if (pos.y + colY > 768) dir.y = -1;
		if (pos.x - colX < 0) dir.x = 1;
		if (pos.x + colX > 1024) dir.x = -1;
		if (getCollider()->CheckCollision(leftP->getCollider(), 1)) { dir.x = 1; speed += dt / 8; }
		if (getCollider()->CheckCollision(rightP->getCollider(), 1)) { dir.x = -1; speed += dt / 8;
		}
		pos += dir * dt * speed;
	}

	void Ball::render(sf::RenderWindow* win) {
		mesh.setPosition(sf::Vector2f(pos.x-colX, pos.y-colY));
		win->draw(Ball::mesh);
	}

	float Ball::getColX() {
		return colX;
	}

	float Ball::getColY() {
		return colY;
	}
}