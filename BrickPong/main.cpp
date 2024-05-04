#include <SFML/Graphics.hpp>
#include <iostream>
#include "GameScene.h"

using namespace sf;

unsigned int wWidth = 1024, wHeight = 768;
char title[] = "PongBricks";
float fps = 60;

int main (){
	//init----------------------
	RenderWindow window(VideoMode(wWidth, wHeight), title, Style::Default | Style::Resize);
	Scene* scene = new gsc::GameScene(&window);
	
	sf::Image icn;
	icn.loadFromFile("BPIcon.png");
	window.setIcon(icn.getSize().x, icn.getSize().y, icn.getPixelsPtr());

	float dt = 0;
	Clock dtClock;
	//init----------------------

	while(window.isOpen()) {
		//tick------------------
		Time dt = dtClock.restart();
		Event evnt;
		while (window.pollEvent(evnt))
		{
			switch (evnt.type)
			{
			case Event::Closed:
				window.close();
				break;
			case Event::Resized:
				break;
			//case Event::TextEntered:
				//keiboard input
			//	break;
			default:
				break;
			}
		}
		scene->tick(dt.asSeconds() * fps); //am transmis direct dt * fps pt a nu trebui sa mai calculez mai incolo
		//tick------------------

		window.clear(Color::Black);
		//draw here-------------
		scene->render();
		//stop drawing----------
		window.display();
	}

	return 0;
}