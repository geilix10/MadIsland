#include "CollisionSystem.h"
#include "Collision.h"


CollisionSystem::CollisionSystem(player *Player, House *house, Fountain *fountain, trainMob *trainMOB, InDoor *indoor, Shop *shhop)
{
	pPlayer = Player;
	pFountain = fountain;
	pHouse = house;
	trainmob = trainMOB;
	inDoor = indoor;
	CreateAllTrees();
	houseFence = new fence();
	shop = shhop;
}


CollisionSystem::~CollisionSystem()
{
}

sf::Clock damageClock;
sf::Clock mobdamageClock;
bool treeCollision = false;
int treeCollided = 0;
bool verticalCollision = false;
bool horizontalCollision = false;
int fenceCollided = 0;
void CollisionSystem::update(Mob *nightMobs[], int nightMobsize, bool firstNight)
{
	//Fighting
	if (pPlayer->inHouse == false)
	{
		if (firstNight == true)
		{
			for (int i = 0; i < nightMobsize; i++)
			{
				if (Collision::PixelPerfectTest(pPlayer->getSprite(), nightMobs[i]->getSprite()))
				{
					if (damageClock.getElapsedTime().asMilliseconds() >= 500)
					{
						pPlayer->takeDamage(5);
						damageClock.restart();
						std::cout << "Night Mob DMG: " << i << std::endl;
					}
				}
				if (Collision::PixelPerfectTest(nightMobs[i]->getSprite(), pPlayer->getWeaponSprite()))
				{
					if (mobdamageClock.getElapsedTime().asMilliseconds() >= 150)
					{
						mobdamageClock.restart();
						nightMobs[i]->giveDamage(5,pPlayer);
						std::cout << "NightMob verliert leben akt: " << nightMobs[i]->getMobHealth() << " Mob: " << i << std::endl;
						if (nightMobs[i]->getMobHealth() <= 0)
						{
							pPlayer->givePlayerXP(5);
						}
					}
				}
			}
		}
		for (int i = 0; i < MAX_TRAINMOBS; i++)
		{
			if (Collision::PixelPerfectTest(pPlayer->getSprite(), trainmob->getSprite(i)))
			{
				if (damageClock.getElapsedTime().asMilliseconds() >= 500)
				{
					pPlayer->takeDamage(3);
					damageClock.restart();
				}
			}
			if (Collision::PixelPerfectTest(trainmob->getSprite(i), pPlayer->getWeaponSprite()))
			{
				if (mobdamageClock.getElapsedTime().asMilliseconds() >= 150)
				{
					mobdamageClock.restart();
					trainmob->takeDamage(i, 9, pPlayer);
					std::cout << "Mob verliert leben akt: " << trainmob->getMobHealth(i) << " Mob: " << i << std::endl;
					if (trainmob->getMobHealth(i) <= 0)
						pPlayer->givePlayerXP(5);
				}
			}
		}
		//Collisions of Objects
		if (Collision::PixelPerfectTest(pPlayer->getSprite(), pFountain->getSprite()))
		{
			if (pPlayer->cantWalk == 0)
			{
				std::cout << "Fountain Collision" << std::endl;
				int site = pPlayer->getPlayerWalkingSite();
				pPlayer->cantWalk = site;
			}
		}
		else if (Collision::PixelPerfectTest(pPlayer->getSprite(), pHouse->getSprite()))
		{
			if (pPlayer->cantWalk == 0)
			{
				std::cout << "House Collision" << std::endl;
				int site = pPlayer->getPlayerWalkingSite();
				pPlayer->cantWalk = site;
				pPlayer->canEnter = true;
			}
		}
		else
		{
			if (treeCollision == false)
			{
				pPlayer->cantWalk = 0;
				pPlayer->canEnter = false;
			}
		}
		//std::cout << "cantWalk: " << pPlayer->cantWalk << std::endl;
		for (int i = 0; i < MAX_TREES; i++)
		{
			if (Collision::PixelPerfectTest(pPlayer->getSprite(), pTree[i]->getSprite()))
			{
				if (pPlayer->cantWalk == 0)
				{
					int site = pPlayer->getPlayerWalkingSite();
					pPlayer->cantWalk = site;
					std::cout << "Baum Collision: " << i << "cantWalk = " << pPlayer->cantWalk << std::endl;
					treeCollision = true;
					treeCollided = i;
					i = MAX_TREES;
				}
			}
			else
			{
				if (treeCollided == i)
				{
					treeCollision = false;
				}
			}
		}
	}
	else //IS player in House
	{
		for (int i = 0; i < MAX_HORIZONTAL; i++)
		{
			if (Collision::PixelPerfectTest(pPlayer->getSprite(), houseFence->getSprite(i, true)))
			{
				if (pPlayer->cantWalk == 0)
				{
					std::cout << "Horizontal Fence Collision" << std::endl;
					int site = pPlayer->getPlayerWalkingSite();
					pPlayer->cantWalk = site;
					horizontalCollision = true;
					fenceCollided = i;
				}
			}
			else
			{
				if (fenceCollided == i && horizontalCollision == true)
				{
					horizontalCollision = false;
					pPlayer->cantWalk = 0;
				}
			}
		}
		for (int i = 0; i < MAX_VERTICAL; i++)
		{
			if (Collision::PixelPerfectTest(pPlayer->getSprite(), houseFence->getSprite(i,false)))
			{
				if (pPlayer->cantWalk == 0)
				{
					std::cout << "Vertical Fence Collision" << std::endl;
					int site = pPlayer->getPlayerWalkingSite();
					pPlayer->cantWalk = site;
					verticalCollision = true;
					fenceCollided = i;
				}
			}
			else
			{
				if (fenceCollided == i && verticalCollision == true)
				{
					verticalCollision = false;
					pPlayer->cantWalk = 0;
				}
			}
		}
		if (Collision::PixelPerfectTest(pPlayer->getSprite(), inDoor->getSprite()))
		{
			std::cout << "Indoor Collision" << std::endl;
			pPlayer->canEnter = true;
		}
		if (Collision::PixelPerfectTest(pPlayer->getSprite(), shop->getPillSprite()))
		{
			if (pPlayer->cantWalk == 0)
			{
				std::cout << "Pill Collision" << std::endl;
				pPlayer->canBuyEPill = true;
				int site = pPlayer->getPlayerWalkingSite();
				pPlayer->cantWalk = site;
			}
		}
		else if (Collision::PixelPerfectTest(pPlayer->getSprite(), shop->getAmbosSprite()))
		{
			if (pPlayer->cantWalk == 0)
			{
				std::cout << "Ambos Collision" << std::endl;
				pPlayer->canBuyArmor = true;
				int site = pPlayer->getPlayerWalkingSite();
				pPlayer->cantWalk = site;
			}
		}
		else if (Collision::PixelPerfectTest(pPlayer->getSprite(), shop->getLaserSprite()))
		{
			if (pPlayer->cantWalk == 0)
			{
				std::cout << "LaserBeam Collision" << std::endl;
				pPlayer->canBuyLaserBeam = true;
				int site = pPlayer->getPlayerWalkingSite();
				pPlayer->cantWalk = site;
			}
		}
		else if (Collision::PixelPerfectTest(pPlayer->getSprite(), shop->getFireBallSprite()))
		{
			if (pPlayer->cantWalk == 0)
			{
				std::cout << "FireBall Collision" << std::endl;
				pPlayer->canBuyFireBall = true;
				int site = pPlayer->getPlayerWalkingSite();
				pPlayer->cantWalk = site;
			}
		}
		else { pPlayer->canBuyEPill = false; pPlayer->canBuyArmor = false; pPlayer->canBuyLaserBeam = false; if (verticalCollision == false && horizontalCollision == false) { pPlayer->cantWalk = 0; } }
	}
//	std::cout << "CantWalk: " << pPlayer->cantWalk << std::endl;
}

void CollisionSystem::CreateAllTrees()
{
	pTree[0] = new Tree(std::string("Images\\tree.png"), sf::Vector2f(250, 035));
	pTree[1] = new Tree(std::string("Images\\tree.png"), sf::Vector2f(681, 13));
	pTree[2] = new Tree(std::string("Images\\tree.png"), sf::Vector2f(634, 38));
	pTree[3] = new Tree(std::string("Images\\tree.png"), sf::Vector2f(572, 57));
	pTree[4] = new Tree(std::string("Images\\tree.png"), sf::Vector2f(526, 81));
	pTree[5] = new Tree(std::string("Images\\tree.png"), sf::Vector2f(470, 20));
	pTree[6] = new Tree(std::string("Images\\tree.png"), sf::Vector2f(418, 22));
	pTree[7] = new Tree(std::string("Images\\tree.png"), sf::Vector2f(347, 35));
	pTree[8] = new Tree(std::string("Images\\tree.png"), sf::Vector2f(269, 06));
	pTree[9] = new Tree(std::string("Images\\tree.png"), sf::Vector2f(250, 63));
	pTree[10] = new Tree(std::string("Images\\tree.png"), sf::Vector2f(318, 78));
	pTree[11] = new Tree(std::string("Images\\tree.png"), sf::Vector2f(253, 320));
	pTree[12] = new Tree(std::string("Images\\tree.png"), sf::Vector2f(178, 349));
	pTree[13] = new Tree(std::string("Images\\tree.png"), sf::Vector2f(178, 397));
	pTree[14] = new Tree(std::string("Images\\tree.png"), sf::Vector2f(251, 368));
	pTree[15] = new Tree(std::string("Images\\tree.png"), sf::Vector2f(247, 405));
	pTree[16] = new Tree(std::string("Images\\tree.png"), sf::Vector2f(116, 419));
	pTree[17] = new Tree(std::string("Images\\tree.png"), sf::Vector2f(168, 453));
	pTree[18] = new Tree(std::string("Images\\tree.png"), sf::Vector2f(94, 476));
	pTree[19] = new Tree(std::string("Images\\tree.png"), sf::Vector2f(158, 509));
	pTree[20] = new Tree(std::string("Images\\tree.png"), sf::Vector2f(927, 186));
	pTree[21] = new Tree(std::string("Images\\tree.png"), sf::Vector2f(1166, 489));
	pTree[22] = new Tree(std::string("Images\\tree.png"), sf::Vector2f(426, 568));
	pTree[23] = new Tree(std::string("Images\\tree.png"), sf::Vector2f(1030, 438));
	pTree[24] = new Tree(std::string("Images\\tree.png"), sf::Vector2f(792, 185));
	pTree[25] = new Tree(std::string("Images\\tree.png"), sf::Vector2f(1172, 133));
	pTree[26] = new Tree(std::string("Images\\tree.png"), sf::Vector2f(398, 298));
	pTree[27] = new Tree(std::string("Images\\tree.png"), sf::Vector2f(360, 340));
	pTree[28] = new Tree(std::string("Images\\tree.png"), sf::Vector2f(328, 394));
}

