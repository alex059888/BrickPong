#pragma once
#include "SFML/Graphics.hpp"
#include "Brick.h"
#include "Collider.h"
#include "LeftPlayer.h"
#include "RightPlayer.h"

namespace ball {
	class Ball
	{
	public:
		Ball(sf::Vector2f pos, sf::Texture* ballTex);
		~Ball();
		void tick(float dt, br::Brick** bricks, lp::LeftPlayer* leftP, rp::RightPlayer* rightP);
		void render(sf::RenderWindow* win);
		sf::Vector2f pos;
		float getColX();
		float getColY();
		sf::Vector2f dir;
		float speed;
		Collider* getCollider() { return new Collider(&mesh); }

	private:
		float colX, colY;
		sf::RectangleShape mesh;
		sf::Texture* ballTex;
		bool isBoxVisibleAt(sf::Vector2i pos, br::Brick** bricks);
	};
}