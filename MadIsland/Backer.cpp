#include "Backer.h"


Backer::Backer()
{
	backerTexture = new sf::Texture;
	backerSprite = new sf::Sprite;
	textHealth = new sf::Text;
	textCoins = new sf::Text;
	playerHealthBarTexture = new sf::Texture;
	playerHealthBarSprite = new sf::Sprite;
	playerEnergyBarSprite = new sf::Sprite;
	textEnergy = new sf::Text;
	textArmor = new sf::Text;
	playerArmorBarSprite = new sf::Sprite;
	enterText = new sf::Text;
	backerXPTexture = new sf::Texture;
	backerXPSprite = new sf::Sprite;
	backerLevelTexture = new sf::Texture;
	backerLevelSprite = new sf::Sprite;
	backerLevelText = new sf::Text;

	font = new sf::Font;
	if (!font->loadFromFile("Other\\writePack.ttf")) { }

	sf::Image subImage;
	subImage.loadFromFile("Images\\backer.png");
	subImage.createMaskFromColor(sf::Color::White);

	backerTexture->loadFromImage(subImage);
	backerSprite->setTexture(*backerTexture);
	backerSprite->setPosition(sf::Vector2f(0,0));

	textCoins->setFont(*font);
	textCoins->setColor(sf::Color::Black);
	textCoins->setString("0");
	textCoins->setPosition(sf::Vector2f(30.0, 47.0));
	textCoins->scale(0.8f, 0.8f);

	textHealth->setFont(*font);
	textHealth->setColor(sf::Color::Black);
	textHealth->setString("Player-Health");
	textHealth->setPosition(sf::Vector2f(7.0, 0.0));
	textHealth->scale(0.5f, 0.5f);

	playerHealthBarTexture->loadFromFile("Images\\balken.png");
	playerHealthBarSprite->setTexture(*playerHealthBarTexture);
	playerHealthBarSprite->setOrigin(playerHealthBarTexture->getSize().x / 2.0f - 27.0f, playerHealthBarTexture->getSize().y / 2.0f);
	playerHealthBarSprite->setColor(sf::Color::Green);
	//playerHealthBarSprite->setScale(1.0f, 1.0f);
	playerHealthBarSprite->setPosition(150.0f, 10.f);

	playerEnergyBarSprite->setTexture(*playerHealthBarTexture);
	playerEnergyBarSprite->setOrigin(playerHealthBarTexture->getSize().x / 2.0f - 27.0f, playerHealthBarTexture->getSize().y / 2.0f);
	playerEnergyBarSprite->setColor(sf::Color::Yellow);
	//playerHealthBarSprite->setScale(2.0f, 1.0f);
	playerEnergyBarSprite->setPosition(150.0f, 30.f);
	textEnergy->setFont(*font);
	textEnergy->setColor(sf::Color::Black);
	textEnergy->setString("Player-Energy: ");
	textEnergy->setPosition(sf::Vector2f(7.0, 20.0));
	textEnergy->scale(0.5f, 0.5f);

	playerArmorBarSprite->setTexture(*playerHealthBarTexture);
	playerArmorBarSprite->setOrigin(playerHealthBarTexture->getSize().x / 2.0f - 27.0f, playerHealthBarTexture->getSize().y / 2.0f);
	playerArmorBarSprite->setColor(sf::Color::Color(sf::Uint8(0), sf::Uint8(145), sf::Uint8(0), sf::Uint8(255)));
	//playerHealthBarSprite->setScale(2.0f, 1.0f);
	playerArmorBarSprite->setPosition(170.0f, 65.f);
	textArmor->setFont(*font);
	textArmor->setColor(sf::Color::Black);
	textArmor->setString("Armor: ");
	textArmor->setPosition(sf::Vector2f(90.0, 55.0));
	textArmor->scale(0.5f, 0.5f);

	enterText->setFont(*font);
	enterText->setColor(sf::Color::Black);
	enterText->setString("Enter 'F'");
	enterText->setPosition(sf::Vector2f(446.0, 203.0));
	enterText->scale(0.5f, 0.5f);


	backerXPTexture->loadFromFile("Images\\BackerXP.png");
	backerXPSprite->setTexture(*backerXPTexture);
	backerXPSprite->setPosition(sf::Vector2f(0, 600));
	backerXPSprite->scale(0.8f, 0.8f);

	backerLevelTexture->loadFromFile("Images\\level.png");
	backerLevelSprite->setTexture(*backerLevelTexture);
	backerLevelSprite->setPosition(sf::Vector2f(20, 660));
	backerLevelSprite->scale(0.8f, 0.8f);
	backerLevelText->setFont(*font);
	backerLevelText->setColor(sf::Color::Black);
	backerLevelText->setString("1");
	backerLevelText->setPosition(sf::Vector2f(38, 664));
	backerLevelText->scale(0.8f, 0.8f);
}


Backer::~Backer()
{
}

void Backer::render(sf::RenderWindow *window)
{
	window->draw(*backerSprite);
	window->draw(*textHealth);
	window->draw(*textCoins);
	window->draw(*playerHealthBarSprite);
	window->draw(*textEnergy);
	window->draw(*playerEnergyBarSprite);
	window->draw(*textArmor);
	window->draw(*playerArmorBarSprite);
	window->draw(*enterText);
	window->draw(*backerXPSprite);
	window->draw(*backerLevelSprite);
	window->draw(*backerLevelText);
}

void Backer::update(player *pPlayer)
{
	textCoins->setString(std::to_string(pPlayer->getPlayerCoins()));

	playerHealthBarSprite->setTextureRect(sf::IntRect(0, 0, pPlayer->getPlayerHealth(), playerHealthBarTexture->getSize().y));
	int health = pPlayer->getPlayerHealth();
	if (health > 50)
		playerHealthBarSprite->setColor(sf::Color::Green);
	if (health <= 50)
		playerHealthBarSprite->setColor(sf::Color::Yellow);
	if (health <= 25)
		playerHealthBarSprite->setColor(sf::Color::Red);
	textHealth->setString("Player-Health: ");

	playerEnergyBarSprite->setTextureRect(sf::IntRect(0, 0, pPlayer->getPlayerEnergy(), playerHealthBarTexture->getSize().y));

	playerArmorBarSprite->setTextureRect(sf::IntRect(0, 0, pPlayer->getPlayerArmor(), playerHealthBarTexture->getSize().y));
	if (pPlayer->inHouse == false)
	{
		enterText->setString("Enter 'F'");
		enterText->setPosition(sf::Vector2f(446.0, 203.0));
	}
	else
	{
		enterText->setString("Exit 'F'");
		enterText->setPosition(sf::Vector2f(19.0, 284.0));
	}

	backerLevelText->setString(std::to_string(pPlayer->getPlayerLevel()) + "\t\t" + std::to_string(pPlayer->getPlayerXP()) + " / " + std::to_string(pPlayer->getPlayerMaxXP()) + " XP");
}
