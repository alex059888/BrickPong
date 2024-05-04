#pragma once
#include "Scene.h"
#include "Brick.h"
#include "TexturesManager.h"
#include <fstream>
#include "Ball.h"
#include "LeftPlayer.h"
#include "RightPlayer.h"

namespace gsc {
	class GameScene : public Scene
	{
	public:
		GameScene(sf::RenderWindow* win);
		void tick(float dt) override;
		void render() override;
		void loadMap(int n);

	private:
		tex::TextureManager texMan;
		br::Brick* b; 
		sf::RectangleShape* background;
		br::Brick **bricks;
		bool paused, redWon, blueWon;
		sf::RectangleShape* blackScreen;
		ball::Ball* minge;
		lp::LeftPlayer* leftPlayer;
		rp::RightPlayer* rightPlayer;
		sf::RectangleShape *start, *quit, *continu, *bWin, *rWin, *restart;
		bool escPressed;
		int btnSelectMenu, btnSelectWin, firstPause, btnUDPressed;
		void resetAll();
		int nrOfMaps;

	};
}