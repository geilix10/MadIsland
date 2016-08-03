#pragma once

#include <iostream>
#include <SFML\Graphics.hpp>
#define MAX_TREES 29

class Tree
{
public:
	Tree(std::string texturePath,sf::Vector2f pos);
	~Tree();
	void render(sf::RenderWindow *window);
	const sf::Sprite &getSprite() { return *treeSprite; }
private:
	sf::Texture *treeTexture;
	sf::Sprite *treeSprite;
};

