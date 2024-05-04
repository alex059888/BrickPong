#pragma once
#include "SFML/Graphics.hpp"
#include "Collider.h"

namespace rp {
	class RightPlayer
	{
	public:
		RightPlayer(sf::Vector2f pos, sf::Texture* playerTex);
		~RightPlayer();
		void tick(float dt);
		void render(sf::RenderWindow* win);
		sf::Vector2f pos;
		float speed;
		Collider* getCollider() { return new Collider(&mesh); }

	private:
		sf::RectangleShape mesh;
		sf::Texture* playerTex;
		float colX, colY;

	};
}