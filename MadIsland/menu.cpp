#include "menu.h"


menu::menu(float width, float height)
{
	if (!font.loadFromFile("Other\\writePack.ttf"))
	{
		//error handle
	}
	text[0].setFont(font);
	text[0].setColor(sf::Color::Color(sf::Uint8(0), sf::Uint8(218), sf::Uint8(0), sf::Uint8(250)));
	text[0].setString("Play Game");
	text[0].setPosition(sf::Vector2f(width / 2 - 50, height / (MAX_NUMBER_OF_ITEMS + 1) *1 ));
	text[0].setScale(1.2f, 1.2f);
	text[0].setStyle(sf::Text::Bold);

	text[1].setFont(font);
	text[1].setColor(sf::Color::White);
	text[1].setString("Exit Game");
	text[1].setPosition(sf::Vector2f(width / 2-50, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));
	text[1].setStyle(sf::Text::Bold);

	text[2].setFont(font);
	text[2].setColor(sf::Color::White);
	text[2].setString("Credits");
	text[2].setPosition(sf::Vector2f(width / 2 - 50, height / (MAX_NUMBER_OF_ITEMS + 1) * 3));
	text[2].setStyle(sf::Text::Bold);

	selectedItemIDX = 0;
}


menu::~menu()
{
}

void menu::draw(sf::RenderWindow &window)
{
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		window.draw(text[i]);
	}
}


void menu::MoveUp()
{
	if (selectedItemIDX - 1 >= 0)
	{
		text[selectedItemIDX].setColor(sf::Color::White);
		text[selectedItemIDX].setScale(1.0f, 1.0f);
		selectedItemIDX--;
		text[selectedItemIDX].setColor(sf::Color::Color(sf::Uint8(0), sf::Uint8(218), sf::Uint8(0), sf::Uint8(250)));
		text[selectedItemIDX].setScale(1.2f, 1.2f);
	}
}

void menu::MoveDown()
{
	if (selectedItemIDX + 1 < MAX_NUMBER_OF_ITEMS)
	{
		text[selectedItemIDX].setColor(sf::Color::White);
		text[selectedItemIDX].setScale(1.0f, 1.0f);
		selectedItemIDX++;
		text[selectedItemIDX].setScale(1.2f, 1.2f);
		text[selectedItemIDX].setColor(sf::Color::Color(sf::Uint8(0), sf::Uint8(218), sf::Uint8(0), sf::Uint8(250)));
	}
}
