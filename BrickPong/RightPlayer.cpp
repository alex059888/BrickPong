#include "RightPlayer.h"

namespace rp {
	RightPlayer::RightPlayer(sf::Vector2f pos, sf::Texture* playerTex)
	{
		RightPlayer::pos = pos;
		RightPlayer::playerTex = playerTex;
		colX = 16;
		colY = 64;
		mesh.setSize(sf::Vector2f(2 * colX, 2 * colY));
		mesh.setFillColor(sf::Color(255, 255, 255, 255));
		mesh.setTexture(playerTex);
		speed = 7;
		sf::Vector2u texSize = playerTex->getSize();
		texSize.x /= 2;
		texSize.y /= 1;
		mesh.setTextureRect(sf::IntRect(texSize.x * 1, texSize.y * 0, texSize.x, texSize.y));
	}

	RightPlayer::~RightPlayer()
	{
	}

	void RightPlayer::tick(float dt) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && (pos.y - colY) > 0) {
			pos.y -= speed * dt;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && (pos.y + colY) < 768) {
			pos.y += speed * dt;
		}
	}

	void RightPlayer::render(sf::RenderWindow* win) {
		mesh.setPosition(sf::Vector2f(pos.x - colX, pos.y - colY));
		win->draw(RightPlayer::mesh);
	}
}