#pragma once

#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>

#define MAX_NUMBER_OF_ITEMS 3
class menu
{
public:
	menu(float width, float height);
	~menu();

	void draw(sf::RenderWindow &window);
	void MoveUp();
	void MoveDown();
	int getPressedItem() { return selectedItemIDX; }

private:
	int selectedItemIDX;
	sf::Font font;
	sf::Text text[MAX_NUMBER_OF_ITEMS];
};

