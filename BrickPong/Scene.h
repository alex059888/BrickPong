#pragma once
#include "SFML/Graphics.hpp"

class Scene
{
public:
	Scene(sf::RenderWindow* win);
	~Scene();
	virtual void tick(float dt);
	virtual void render();

private:
	
protected:
	sf::RenderWindow* win;
};