#include <iostream>
#include <SFML/Graphics.hpp>
#include "Framework.h"

bool menuActive = true;
menu Menu(VM_WIDTH, VM_HEIGHT);
bool creditsActive = false;
int main()
{
	if (menuActive == true)
	{
		sf::RenderWindow window(sf::VideoMode(VM_WIDTH, VM_HEIGHT), GUI_TITLE);
		sf::SoundBuffer buffer;
		sf::Sound sound;
		if (!buffer.loadFromFile("Sounds\\SoundIntro.wav"))  {}
		//return -1;
		sound.setBuffer(buffer);
		sound.play();
		sound.setVolume(50);
		sf::Texture credits;
		credits.loadFromFile("Images\\credits.png");
		sf::Sprite creditsSprite;
		creditsSprite.setTexture(credits);
		creditsSprite.setPosition(sf::Vector2f(VM_WIDTH / 2.0f, 750.0f));

		while (window.isOpen() && menuActive == true)
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				switch (event.type)
				{
				case sf::Event::KeyPressed:
				{
					switch (event.key.code)
					{
					case sf::Keyboard::Up:
					{
						Menu.MoveUp();
						break;
					}
					case sf::Keyboard::Down:
					{
						Menu.MoveDown();
						break;
					}
					case sf::Keyboard::Return:
					{
						switch (Menu.getPressedItem())
						{
						case 0:
							menuActive = false;
							sound.stop();
							break;
						case 1:
							window.close();
							break;
						case 2:
							creditsActive = true;
							break;
						}
					}
					}
					break;
				}
				case sf::Event::Closed:
				{
					window.close();
					break;
				}
				}
			}

			window.clear();

			sf::Texture img;
			if (!img.loadFromFile("Images\\menuBackground.png")) {}
			sf::Sprite sprite;
			sprite.setTexture(img);
			window.draw(sprite);
			if (creditsActive == true)
			{
				creditsSprite.setPosition(sf::Vector2f(VM_WIDTH / 2.0f - 200, creditsSprite.getPosition().y-2));
				window.draw(creditsSprite);
				if (creditsSprite.getPosition().y < -650)
					creditsActive = false;
				std::cout << "Pos: " << creditsSprite.getPosition().y << std::endl;
			}
			else
			{
				Menu.draw(window);
			}
			sf::Sound::Status introStatus = sound.getStatus();
			//std::cout << introStatus << std::endl;
			if (introStatus == sf::Sound::Stopped)
			{
				sound.play();
			}
			window.display();
		}
	}
	if (menuActive == false)
	{
		Framework framework;
		framework.run();
	}
	return 0;
}