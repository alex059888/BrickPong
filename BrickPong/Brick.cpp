#include "Brick.h"

namespace br {
	Brick::Brick(sf::Vector2f pos, int texId, sf::Texture* bricksTexture)
	{
		visible = 1;
		Brick::pos = pos;
		Brick::texId = texId;
		Brick::bricksTexture = bricksTexture;
		Brick::colX = 32.0f;
		Brick::colY = 16.0f;
		Brick::mesh.setSize(sf::Vector2f(2*colX,2*colY));
		Brick::mesh.setFillColor(sf::Color(255, 255, 255, 255));
		Brick::mesh.setTexture(bricksTexture);
		sf::Vector2u texSize = bricksTexture->getSize();
		texSize.x /= 2;
		texSize.y /= 4;
		switch (texId)
		{
		case 0:
			mesh.setTextureRect(sf::IntRect(texSize.x * 0, texSize.y * 0,texSize.x, texSize.y));
			break;
		case 1:
			mesh.setTextureRect(sf::IntRect(texSize.x * 1, texSize.y * 0, texSize.x, texSize.y));
			break;
		case 2:
			mesh.setTextureRect(sf::IntRect(texSize.x * 0, texSize.y * 1, texSize.x, texSize.y));
			break;
		case 3:
			mesh.setTextureRect(sf::IntRect(texSize.x * 1, texSize.y * 1, texSize.x, texSize.y));
			break;
		case 4:
			mesh.setTextureRect(sf::IntRect(texSize.x * 0, texSize.y * 2, texSize.x, texSize.y));
			break;
		case 5:
			mesh.setTextureRect(sf::IntRect(texSize.x * 1, texSize.y * 2, texSize.x, texSize.y));
			break;
		case 6:
			mesh.setTextureRect(sf::IntRect(texSize.x * 0, texSize.y * 3, texSize.x, texSize.y));
			break;
		default:
			mesh.setTextureRect(sf::IntRect(texSize.x * 1, texSize.y * 3, texSize.x, texSize.y));
			break;
		}
	}

	Brick::Brick() {
		visible = 0;
	}

	Brick::~Brick()
	{
	}

	void Brick::tick(float dt) {
	}

	void Brick::render(sf::RenderWindow* win) {
		if (visible) {
			Brick::mesh.setPosition(sf::Vector2f(Brick::pos.x - Brick::colX, Brick::pos.y - Brick::colY));
			win->draw(Brick::mesh);
		}
	}
	float Brick::getColX() {
		return colX;
	}

	float Brick::getColY() {
		return colY;
	}

	int Brick::getTexId() {
		return texId;
	}

	bool Brick::isVisible() {
		return visible;
	}

	void Brick::shatter() {
		visible = 0;
	}
}