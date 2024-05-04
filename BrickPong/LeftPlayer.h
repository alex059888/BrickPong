#pragma once
#include "SFML/Graphics.hpp"
#include "Collider.h"

namespace lp {
	class LeftPlayer
	{
	public:
		LeftPlayer(sf::Vector2f pos, sf::Texture* playerTex);
		~LeftPlayer();
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