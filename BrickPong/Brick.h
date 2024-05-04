#pragma once
#include <math.h>
#include "SFML/Graphics.hpp"
#include "Collider.h"

namespace br {
	class Brick
	{
	public:
		Brick(sf::Vector2f pos, int texId, sf::Texture* bricksTexture);
		Brick();
		~Brick();
		void tick(float dt);
		void render(sf::RenderWindow* win);
		sf::Vector2f pos;
		float getColX();
		float getColY();
		int getTexId();
		bool isVisible();
		void shatter();
		Collider* getCollider() { return new Collider(&mesh); }

	private:
		float colX, colY;
		sf::RectangleShape mesh;
		int texId;
		sf::Texture* bricksTexture;
		bool visible;
	};
}
