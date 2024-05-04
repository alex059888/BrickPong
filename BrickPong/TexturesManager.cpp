#include "TexturesManager.h"

namespace tex {
	TextureManager::TextureManager()
	{
		bricksL = 0;
		playerL = 0;
		backgroundL = 0;
		buttonsL = 0;
		ballL = 0;
	}

	TextureManager::~TextureManager()
	{
	}

	sf::Texture TextureManager::getBricksTex() { return bricks; }

	sf::Texture TextureManager::getPlayerTex() { return player; }

	sf::Texture TextureManager::getBackgroundTex() { return background; }

	sf::Texture TextureManager::getButtonsTex() { return buttons; }

	sf::Texture TextureManager::getBallTex() { return ball; }

	sf::Texture* TextureManager::getBricksTexP() { return &bricks; }

	sf::Texture* TextureManager::getPlayerTexP() { return &player; }

	sf::Texture* TextureManager::getBackgroundTexP() { return &background; }

	sf::Texture* TextureManager::getButtonsTexP() { return &buttons; }

	sf::Texture* TextureManager::getBallTexP() { return &ball; }

	sf::Texture* TextureManager::getContinueTexP() { return &continu; }

	sf::Texture* TextureManager::getQuitTexP() { return &quit; }

	sf::Texture* TextureManager::getRWinTexP() { return &rWin; }

	sf::Texture* TextureManager::getBWinTexP() { return &bWin; }

	sf::Texture* TextureManager::getRestartTexP() { return &restart; }

	sf::Texture* TextureManager::getStartTexP() { return &start; }

	bool TextureManager::isBricksLoaded() { return bricksL; }

	bool TextureManager::isPlayerLoaded() { return playerL; }

	bool TextureManager::isBackgroundLoaded() { return backgroundL; }

	bool TextureManager::isButtonsLoaded() { return buttonsL; }

	bool TextureManager::isBallLoaded() { return ballL; }

	bool TextureManager::isContinueLoaded() { return continuL; }

	bool TextureManager::isQuitLoaded() { return quitL; }

	bool TextureManager::isRWinLoaded() { return rWinL; }

	bool TextureManager::isBWinLoaded() { return bWinL; }

	bool TextureManager::isRestartLoaded() { return restartL; }

	bool TextureManager::isStartLoaded() { return startL; }

	void TextureManager::loadBricksTex() {
		bricks.loadFromFile("Bricks.png");
		bricksL = 1;
	}

	void TextureManager::loadPlayerTex() {
		player.loadFromFile("Player.png");
		playerL = 1;
	}

	void TextureManager::loadBackgroundTex() {
		background.loadFromFile("Background.png");
		backgroundL = 1;
	}

	void TextureManager::loadButtonsTex() {
		buttons.loadFromFile("Buttons.png");
		buttonsL = 1;
	}

	void TextureManager::loadBallTex() {
		ball.loadFromFile("Ball.png");
		ballL = 1;
	}
	void TextureManager::loadContinueTex() {
		continu.loadFromFile("Continue.png");
		continuL = 1;
	}

	void TextureManager::loadQuitTex() {
		quit.loadFromFile("Quit.png");
		quitL = 1;
	}

	void TextureManager::loadRWinTex() {
		rWin.loadFromFile("RedWins.png");
		rWinL = 1;
	}

	void TextureManager::loadBWinTex() {
		bWin.loadFromFile("BlueWins.png");
		bWinL = 1;
	}

	void TextureManager::loadRestartTex() {
		restart.loadFromFile("Restart.png");
		restartL = 1;
	}

	void TextureManager::loadStartTex() {
		start.loadFromFile("Start.png");
		startL = 1;
	}

	void TextureManager::loadBricksTex(char* path) {
		bricks.loadFromFile(path);
		bricksL = 1;
	}

	void TextureManager::loadPlayerTex(char* path) {
		player.loadFromFile(path);
		playerL = 1;
	}

	void TextureManager::loadBackgroundTex(char* path) {
		background.loadFromFile(path);
		backgroundL = 1;
	}

	void TextureManager::loadButtonsTex(char* path) {
		buttons.loadFromFile(path);
		buttonsL = 1;
	}

	void TextureManager::loadBallTex(char* path) {
		ball.loadFromFile(path);
		ballL = 1;
	}

	void TextureManager::loadContinueTex(char* path) {
		continu.loadFromFile(path);
		continuL = 1;
	}

	void TextureManager::loadQuitTex(char* path) {
		quit.loadFromFile(path);
		quitL = 1;
	}

	void TextureManager::loadRWinTex(char* path) {
		rWin.loadFromFile(path);
		rWinL = 1;
	}

	void TextureManager::loadBWinTex(char* path) {
		ball.loadFromFile(path);
		bWinL = 1;
	}

	void TextureManager::loadRestartTex(char* path) {
		restart.loadFromFile(path);
		restartL = 1;
	}

	void TextureManager::loadStartTex(char* path) {
		start.loadFromFile(path);
		startL = 1;
	}
}