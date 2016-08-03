#pragma once

#include <iostream>
#include <SFML\Graphics.hpp>

class Fountain
{
public:
	Fountain(sf::Vector2f pos);
	~Fountain();
	void render(sf::RenderWindow *window);
	void update();
	const sf::Sprite &getSprite() { return *fountainSprite; }
	sf::Texture *fountainTexture;
	sf::Sprite *fountainSprite;
private:
};

