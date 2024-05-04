#include "GameScene.h"

namespace gsc {
	GameScene::GameScene(sf::RenderWindow* win) : Scene(win) {
		texMan.loadBricksTex();
		texMan.loadBackgroundTex();
		texMan.loadBallTex();
		texMan.loadPlayerTex();
		texMan.loadBWinTex();
		texMan.loadRWinTex();
		texMan.loadQuitTex();
		texMan.loadContinueTex();
		texMan.loadRestartTex();
		texMan.loadStartTex();
		background = new sf::RectangleShape(sf::Vector2f(1024, 768));
		background->setFillColor(sf::Color(255,255,255,255));
		background->setTexture(texMan.getBackgroundTexP());
		background->setPosition(sf::Vector2f(0, 0));
		loadMap(0);
		paused = 1; redWon = 0; blueWon = 0;
		blackScreen = new sf::RectangleShape(sf::Vector2f(1024,768));
		blackScreen->setPosition(sf::Vector2f(0, 0));
		blackScreen->setFillColor(sf::Color(0,0,0,155));
		minge = new ball::Ball(sf::Vector2f(1024/2,768/2),texMan.getBallTexP());
		leftPlayer = new lp::LeftPlayer(sf::Vector2f(64, 384), texMan.getPlayerTexP());
		rightPlayer = new rp::RightPlayer(sf::Vector2f(960, 384), texMan.getPlayerTexP());

		bWin = new sf::RectangleShape(sf::Vector2f(296, 40));
		bWin->setFillColor(sf::Color(255, 255, 255, 255));
		bWin->setTexture(texMan.getBWinTexP());
		bWin->setPosition(sf::Vector2f(512 - 148, 150 - 20));

		rWin = new sf::RectangleShape(sf::Vector2f(256, 40));
		rWin->setFillColor(sf::Color(255, 255, 255, 255));
		rWin->setTexture(texMan.getRWinTexP());
		rWin->setPosition(sf::Vector2f(512 - 128, 150 - 20));

		start = new sf::RectangleShape(sf::Vector2f(80,20));
		start->setFillColor(sf::Color(255, 255, 255, 255));
		start->setTexture(texMan.getStartTexP());
		start->setPosition(sf::Vector2f(512 - 40, 300 - 10));

		quit = new sf::RectangleShape(sf::Vector2f(64, 20));
		quit->setFillColor(sf::Color(255, 255, 255, 255));
		quit->setTexture(texMan.getQuitTexP());
		quit->setPosition(sf::Vector2f(512 - 32, 400 - 10));

		restart = new sf::RectangleShape(sf::Vector2f(112, 20));
		restart->setFillColor(sf::Color(255, 255, 255, 255));
		restart->setTexture(texMan.getRestartTexP());
		restart->setPosition(sf::Vector2f(512 - 56, 300 - 10));

		continu = new sf::RectangleShape(sf::Vector2f(136, 20));
		continu->setFillColor(sf::Color(255, 255, 255, 255));
		continu->setTexture(texMan.getContinueTexP());
		continu->setPosition(sf::Vector2f(512 - 68, 200 - 10));

		escPressed = 0; btnSelectMenu = 0; btnSelectWin = 0; firstPause = 1; btnUDPressed = 0; nrOfMaps = 2;
	}

	void GameScene::loadMap(int n) {
		std::ifstream fin;
		switch (n)
		{
		case -2:
			fin.open("PattEmpty.txt");
			break;
		case -1:
			fin.open("PattFull.txt");
			break;
		case 1:
			fin.open("Pat1.txt");
			break;
		default:
			fin.open("Pat0.txt");
			break;
		}
		bricks = new br::Brick * [16];
		for (int i = 0; i < 16; i++)
			bricks[i] = new br::Brick[24];
		int m;
		for (int j = 0; j < 24; j++)
			for (int i = 0; i < 16; i++) {
				fin >> m;
				if (m > 8 || m < 1)
					bricks[i][j] = br::Brick();
				else
					bricks[i][j] = br::Brick(sf::Vector2f(i * 64 + 32, j * 32 + 16), m - 1, texMan.getBricksTexP());
			}
		fin.close();
	}

	void GameScene::resetAll() {
		std::srand(std::time(nullptr));
		int mapNr = std::rand() % nrOfMaps;
		paused = 0;
		escPressed = 0;
		loadMap(mapNr);
		minge->pos = sf::Vector2f(1024 / 2, 768 / 2);
		leftPlayer->pos = sf::Vector2f(64, 384);
		rightPlayer->pos = sf::Vector2f(960, 384);
		blueWon = 0;
		redWon = 0;
	}

	void GameScene::tick(float dt) {
		if(!paused && !blueWon && !redWon) {
			leftPlayer->tick(dt);
			rightPlayer->tick(dt);
			minge->tick(dt, bricks, leftPlayer, rightPlayer);
			if (minge->pos.x <= 10.0f) blueWon = 1;
			if (minge->pos.x >= 1014.0f) redWon = 1;
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && !escPressed) {
				paused = 1; 
				escPressed = 1;
			}
			if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && escPressed)
			{
				escPressed = 0;
			}
		} else if(paused && !firstPause) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && !escPressed) {
				paused = 0;
				escPressed = 1;
			}
			if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && escPressed)
			{
				escPressed = 0;
			}
			//verif btns 0 continua 2 restart 1 quit
			switch (btnSelectMenu)
			{
			case 0:
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
					paused = 0;
					escPressed = 0;
				}
				break;
			case 1:
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
					win->close();
				}
				break;
			case 2:
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
					resetAll();
				}
				break;
			default:
				break;
			}
			//verif btns
			if (!btnUDPressed) {
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
					btnSelectMenu = (btnSelectMenu + 1) % 3;
					btnUDPressed = 1;
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
					if (btnSelectMenu == 0) btnSelectMenu = 2;
					else btnSelectMenu = abs(btnSelectMenu - 1) % 3;
					btnUDPressed = 1;
				}
			}
			else if (btnUDPressed && !sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
				btnUDPressed = 0;
			}
		}
		else if (paused && firstPause) {
			if (btnSelectMenu == 0) {
				//start selected
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
					firstPause = 0;
					paused = 0;
				}
			}
			if (btnSelectMenu == 1) {
				//quit selected
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
					win->close();
				}
			}
			if (!btnUDPressed) {
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
					btnSelectMenu = (btnSelectMenu + 1) % 2;
					btnUDPressed = 1;
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
					btnSelectMenu = abs(btnSelectMenu - 1) % 2;
					btnUDPressed = 1;
				}
			} else if (btnUDPressed && !sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
				btnUDPressed = 0;
			}
		}
		else if (blueWon || redWon) {
			if (btnSelectWin == 1 && sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) win->close();
			if (btnSelectWin == 0 && sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) resetAll();
			if (!btnUDPressed) {
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
					btnSelectWin = (btnSelectWin + 1) % 2;
					btnUDPressed = 1;
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
					btnSelectWin = abs(btnSelectWin - 1) % 2;
					btnUDPressed = 1;
				}
			}
			else if (btnUDPressed && !sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
				btnUDPressed = 0;
			}
		}
	}

	void GameScene::render() {
		win->draw(*background);
		//Draw Bricks
		for (int i = 0; i < 16; i++)
			for (int j = 0; j < 24; j++)
				bricks[i][j].render(win);
		leftPlayer->render(win);
		rightPlayer->render(win);
		minge->render(win);
		if(paused) {
			win->draw(*blackScreen);
			if (firstPause) {
				sf::Vector2u texSize(20,10);
				texSize.x /= 1;
				texSize.y /= 2;
				if (btnSelectMenu == 0) {
					start->setTextureRect(sf::IntRect(texSize.x * 0, texSize.y * 0, texSize.x, texSize.y));
				}
				else {
					start->setTextureRect(sf::IntRect(texSize.x * 0, texSize.y * 1, texSize.x, texSize.y));
				}
				win->draw(*start);
			}
			else {
				sf::Vector2u texSizeCon(34, 10);
				texSizeCon.x /= 1;
				texSizeCon.y /= 2;
				if (btnSelectMenu == 0) {
					continu->setTextureRect(sf::IntRect(texSizeCon.x * 0, texSizeCon.y * 0, texSizeCon.x, texSizeCon.y));
				}
				else {
					continu->setTextureRect(sf::IntRect(texSizeCon.x * 0, texSizeCon.y * 1, texSizeCon.x, texSizeCon.y));
				}
				win->draw(*continu); 
				sf::Vector2u texSizeRest(28, 10);
				texSizeRest.x /= 1;
				texSizeRest.y /= 2;
				if (btnSelectMenu == 2) {
					restart->setTextureRect(sf::IntRect(texSizeRest.x * 0, texSizeRest.y * 0, texSizeRest.x, texSizeRest.y));
				}
				else {
					restart->setTextureRect(sf::IntRect(texSizeRest.x * 0, texSizeRest.y * 1, texSizeRest.x, texSizeRest.y));
				}
				win->draw(*restart);
			}
			sf::Vector2u texSizeQu(16, 10);
			texSizeQu.x /= 1;
			texSizeQu.y /= 2;
			if (btnSelectMenu == 1) {
				quit->setTextureRect(sf::IntRect(texSizeQu.x * 0, texSizeQu.y * 0, texSizeQu.x, texSizeQu.y));
			}
			else {
				quit->setTextureRect(sf::IntRect(texSizeQu.x * 0, texSizeQu.y * 1, texSizeQu.x, texSizeQu.y));
			}
			win->draw(*quit);
		}
		else if (redWon || blueWon) {
			win->draw(*blackScreen);
			if(redWon)
				win->draw(*rWin);
			if(blueWon)
				win->draw(*bWin);
			sf::Vector2u texSizeRest(28, 10);
			texSizeRest.x /= 1;
			texSizeRest.y /= 2;
			if (btnSelectWin == 0) {
				restart->setTextureRect(sf::IntRect(texSizeRest.x * 0, texSizeRest.y * 0, texSizeRest.x, texSizeRest.y));
			}
			else {
				restart->setTextureRect(sf::IntRect(texSizeRest.x * 0, texSizeRest.y * 1, texSizeRest.x, texSizeRest.y));
			}
			win->draw(*restart);
			sf::Vector2u texSizeQu(16, 10);
			texSizeQu.x /= 1;
			texSizeQu.y /= 2;
			if (btnSelectWin == 1) {
				quit->setTextureRect(sf::IntRect(texSizeQu.x * 0, texSizeQu.y * 0, texSizeQu.x, texSizeQu.y));
			}
			else {
				quit->setTextureRect(sf::IntRect(texSizeQu.x * 0, texSizeQu.y * 1, texSizeQu.x, texSizeQu.y));
			}
			win->draw(*quit);
		}
	}
}