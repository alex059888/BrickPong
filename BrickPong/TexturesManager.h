#pragma once
#include "SFML/Graphics.hpp"

namespace tex {
	class TextureManager
	{
	public:
		TextureManager();
		~TextureManager();
		sf::Texture getBricksTex();
		sf::Texture getPlayerTex();
		sf::Texture getBackgroundTex();
		sf::Texture getButtonsTex();
		sf::Texture getBallTex();
		sf::Texture* getBricksTexP();
		sf::Texture* getPlayerTexP();
		sf::Texture* getBackgroundTexP();
		sf::Texture* getButtonsTexP();
		sf::Texture* getBallTexP();
		sf::Texture* getContinueTexP();
		sf::Texture* getQuitTexP();
		sf::Texture* getRWinTexP();
		sf::Texture* getBWinTexP();
		sf::Texture* getRestartTexP();
		sf::Texture* getStartTexP();
		bool isBricksLoaded();
		bool isPlayerLoaded();
		bool isBackgroundLoaded();
		bool isButtonsLoaded();
		bool isBallLoaded();
		bool isContinueLoaded();
		bool isQuitLoaded();
		bool isRWinLoaded();
		bool isBWinLoaded();
		bool isRestartLoaded();
		bool isStartLoaded();
		void loadBricksTex();
		void loadPlayerTex();
		void loadBackgroundTex();
		void loadButtonsTex();
		void loadBallTex();
		void loadContinueTex();
		void loadQuitTex();
		void loadRWinTex();
		void loadBWinTex();
		void loadRestartTex();
		void loadStartTex();
		void loadBricksTex(char* path);
		void loadPlayerTex(char* path);
		void loadBackgroundTex(char* path);
		void loadButtonsTex(char* path);
		void loadBallTex(char* path);
		void loadContinueTex(char* path);
		void loadQuitTex(char* path);
		void loadRWinTex(char* path);
		void loadBWinTex(char* path);
		void loadRestartTex(char* path);
		void loadStartTex(char* path);

	private:
		sf::Texture bricks, player, background, buttons, ball, continu, quit, rWin,bWin, restart, start;
		bool bricksL, playerL, backgroundL, buttonsL, ballL, continuL, quitL, rWinL, bWinL, restartL, startL;
	};
}