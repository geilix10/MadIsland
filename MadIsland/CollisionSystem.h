#pragma once

#include <iostream>
#include <list>
#include <SFML\Graphics.hpp>
#include "player.h"
#include "Tree.h"
#include "House.h"
#include "Fountain.h"
#include "trainMob.h"
#include "InDoor.h"
#include "fence.h"
#include "Shop.h"
#include "Mob.h"

class CollisionSystem
{
public:
	CollisionSystem(player *Player, House *house, Fountain *fountain, trainMob *trainMOB,InDoor *indoor,Shop *shhop);
	~CollisionSystem();
	void update(Mob *nightMods[], int nightMobsize, bool firstNight);
private:
	player *pPlayer;
	Tree *pTree[MAX_TREES];
	House *pHouse;
	Fountain *pFountain;
	trainMob *trainmob;
	InDoor *inDoor;
	fence *houseFence;
	Shop *shop;
	void CreateAllTrees();
};

