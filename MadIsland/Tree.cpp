#include "Tree.h"


Tree::Tree(std::string texturePath, sf::Vector2f pos)
{
	treeTexture = new sf::Texture;
	treeSprite = new sf::Sprite;

	sf::Image subImage;
	subImage.loadFromFile(texturePath);
	subImage.createMaskFromColor(sf::Color::White);

	treeTexture->loadFromImage(subImage);
	treeSprite->setTexture(*treeTexture);
	treeSprite->setPosition(pos);
	treeSprite->setScale(0.9f, 0.9f);

}


Tree::~Tree()
{
}

void Tree::render(sf::RenderWindow *window)
{
	window->draw(*treeSprite);
}
