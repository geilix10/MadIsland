#include "Framework.h"



Framework::Framework()
{
	fRenderWindow		= new sf::RenderWindow(sf::VideoMode(VM_WIDTH, VM_HEIGHT), GUI_TITLE);
	fMainEvent			= new sf::Event;
	fClock				= new sf::Clock;
	fBackground			= new sf::Texture;
	fSprite				= new sf::Sprite;
	fRun = true;
	LoadDayNightImages();
	nightClock			= new sf::Clock;
	houseBackground = new sf::Texture;
	houseSprite = new sf::Sprite;

	fBackground->loadFromFile("Images\\background.png");
	fSprite->setTexture(*fBackground);

	houseBackground->loadFromFile("Images\\houseBackground.png");
	houseSprite->setTexture(*houseBackground);

	Character = new player(std::string("Images\\Character_Sprites_Walking_Downwards.png"), sf::Vector2f(252, 230));
	CreateAllTrees();

	house = new House(std::string("Images\\house.png"), sf::Vector2f(435, 10));
	fountain = new Fountain(sf::Vector2f(435, 450));
	backer = new Backer();
	trainmob = new trainMob(std::string("Images\\trainMob.png"));
	inDoor = new InDoor(std::string("Images\\Door(inside).png"));
	houseFence = new fence();
	shop = new Shop();
	isNight = false;
	firstNight = false;
	collisionSystem = new CollisionSystem(Character,house,fountain,trainmob,inDoor,shop);
}


Framework::~Framework()
{
}

void Framework::run()
{
	while (fRun == true)
	{
		calcFrameTime();
		update(frameTime);
		handleEvents();
		render();

		quit();
	}
}

void Framework::quit()
{
	if (fRun == false)
	{
		fRenderWindow->close();
	}
}

void Framework::update(float frametime)
{
	if (Character->gameOver == false)
	{
		Character->update(frametime);
		fountain->update();
		if (isNight == true || firstNight == true)
		{
			for (int i = 0; i < MAX_NIGHTMOBS; i++)
			{
				nightMobs[i]->update(frametime, Character);
				if (nightMobs[i]->getMobHealth() <= 0)
					nightMobs[i]->resetSprite();
			}
		}
		collisionSystem->update(nightMobs,MAX_NIGHTMOBS,firstNight);
		backer->update(Character);
		if (Character->inHouse == true)
		{
			shop->update();
		}		
	}
}

void Framework::handleEvents()
{
	while (fRenderWindow->pollEvent(*fMainEvent))
	{
		if (fMainEvent->type == sf::Event::Closed)
		{
			fRun = false;
		}
		Character->handle();
	}
}

void Framework::render()
{
	fRenderWindow->clear();
	if (Character->inHouse == false)
	{
		fRenderWindow->draw(*fSprite);
		if (isNight == true || firstNight == true)
		{
			for (int i = 0; i < MAX_NIGHTMOBS; i++)
			{
				nightMobs[i]->render(fRenderWindow);
				firstNight = true;
			}
		}
		trainmob->render(fRenderWindow);
		Character->render(fRenderWindow);
		for (int i = 0; i < MAX_TREES; i++)
		{
			tree[i]->render(fRenderWindow);
		}
		house->render(fRenderWindow);
		fountain->render(fRenderWindow);

		backer->render(fRenderWindow);
		fRenderWindow->draw(*nightSprite[NightSystem()]);

		if (Character->gameOver == true)
		{
			sf::Texture gameover;
			gameover.loadFromFile("Images\\gameover.png");
			sf::Sprite gameoverSprite;
			gameoverSprite.setTexture(gameover);
			fRenderWindow->draw(gameoverSprite);
		}
	}
	else
	{
		fRenderWindow->draw(*houseSprite);
		inDoor->render(fRenderWindow);
	    houseFence->render(fRenderWindow);
		shop->render(fRenderWindow);
		Character->render(fRenderWindow);
		backer->render(fRenderWindow);
	}
	fRenderWindow->display();
}

void Framework::calcFrameTime()
{
	frameTime = fClock->getElapsedTime().asSeconds();
	fClock->restart();
	//std::cout << "FrameTime: " << frameTime << std::endl;
}

void Framework::CreateAllTrees()
{
	tree[0] = new Tree(std::string("Images\\tree.png"), sf::Vector2f(250, 035));
	tree[1] = new Tree(std::string("Images\\tree.png"), sf::Vector2f(681, 13));
	tree[2] = new Tree(std::string("Images\\tree.png"), sf::Vector2f(634, 38));
	tree[3] = new Tree(std::string("Images\\tree.png"), sf::Vector2f(572, 57));
	tree[4] = new Tree(std::string("Images\\tree.png"), sf::Vector2f(526, 81));
	tree[5] = new Tree(std::string("Images\\tree.png"), sf::Vector2f(470, 20));
	tree[6] = new Tree(std::string("Images\\tree.png"), sf::Vector2f(418, 22));
	tree[7] = new Tree(std::string("Images\\tree.png"), sf::Vector2f(347, 35));
	tree[8] = new Tree(std::string("Images\\tree.png"), sf::Vector2f(269, 06));
	tree[9] = new Tree(std::string("Images\\tree.png"), sf::Vector2f(250, 63));
	tree[10] = new Tree(std::string("Images\\tree.png"), sf::Vector2f(318, 78));
	tree[11] = new Tree(std::string("Images\\tree.png"), sf::Vector2f(253, 320));
	tree[12] = new Tree(std::string("Images\\tree.png"), sf::Vector2f(178, 349));
	tree[13] = new Tree(std::string("Images\\tree.png"), sf::Vector2f(178, 397));
	tree[14] = new Tree(std::string("Images\\tree.png"), sf::Vector2f(251, 368));
	tree[15] = new Tree(std::string("Images\\tree.png"), sf::Vector2f(247, 405));
	tree[16] = new Tree(std::string("Images\\tree.png"), sf::Vector2f(116, 419));
	tree[17] = new Tree(std::string("Images\\tree.png"), sf::Vector2f(168, 453));
	tree[18] = new Tree(std::string("Images\\tree.png"), sf::Vector2f(94, 476));
	tree[19] = new Tree(std::string("Images\\tree.png"), sf::Vector2f(158, 509));
	tree[20] = new Tree(std::string("Images\\tree.png"), sf::Vector2f(927, 186));
	tree[21] = new Tree(std::string("Images\\tree.png"), sf::Vector2f(1166, 489));
	tree[22] = new Tree(std::string("Images\\tree.png"), sf::Vector2f(426, 568));
	tree[23] = new Tree(std::string("Images\\tree.png"), sf::Vector2f(1030, 438));
	tree[24] = new Tree(std::string("Images\\tree.png"), sf::Vector2f(792, 185));
	tree[25] = new Tree(std::string("Images\\tree.png"), sf::Vector2f(1172, 133));
	tree[26] = new Tree(std::string("Images\\tree.png"), sf::Vector2f(398, 298));
	tree[27] = new Tree(std::string("Images\\tree.png"), sf::Vector2f(360, 340));
	tree[28] = new Tree(std::string("Images\\tree.png"), sf::Vector2f(328, 394));
}

void Framework::LoadDayNightImages()
{
	for (int i = 0; i < 8; i++)
	{
		nightTexture[i] = new sf::Texture;
		nightSprite[i] = new sf::Sprite;
	}

	nightTexture[0]->loadFromFile("Images\\Day.png");
	nightTexture[1]->loadFromFile("Images\\Night2.png");
	nightTexture[2]->loadFromFile("Images\\Night3.png");
	nightTexture[3]->loadFromFile("Images\\Night4.png");
	nightTexture[4]->loadFromFile("Images\\Night.png");
	nightTexture[5]->loadFromFile("Images\\Night4.png");
	nightTexture[6]->loadFromFile("Images\\Night3.png");
	nightTexture[7]->loadFromFile("Images\\Night2.png");

	nightSprite[0]->setTexture(*nightTexture[0]);
	nightSprite[1]->setTexture(*nightTexture[1]);
	nightSprite[2]->setTexture(*nightTexture[2]);
	nightSprite[3]->setTexture(*nightTexture[3]);
	nightSprite[4]->setTexture(*nightTexture[4]);
	nightSprite[5]->setTexture(*nightTexture[5]);
	nightSprite[6]->setTexture(*nightTexture[6]);
	nightSprite[7]->setTexture(*nightTexture[7]);
}

int nr;
int Framework::NightSystem()
{
	if (nightClock->getElapsedTime().asSeconds() >= MAX_DELAY_NIGHT_SYSTEM)
	{
		nightClock->restart();
		isNight = true;
		nr++;
		if (nr == 8)
		{
			nr = 0;
			isNight = false;
		}
		if (nr == 1)
		{
			for (int i = 0; i < MAX_NIGHTMOBS; i++)
			{
				nightMobs[i] = new Mob(sf::Vector2f(RandomFloat(0, VM_WIDTH), RandomFloat(0, VM_HEIGHT)));
				std::cout << "Mob Pos: " << nightMobs[i]->getSprite().getPosition().x << " Y: " << nightMobs[i]->getSprite().getPosition().y << std::endl;
			}
		}
	}
	return nr;
}

int Framework::RandomFloat(int a, int b)
{
	std::default_random_engine random_engine;
	random_engine.seed(std::random_device()());

	std::uniform_int_distribution<int> distribution(a, b);
	int deinRandomDing = distribution(random_engine);
	return deinRandomDing;
}
