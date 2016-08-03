#pragma once

#include <iostream>
#include <random>
#include <SFML\Graphics.hpp>
#include "menu.h"
#include "player.h"
#include "Tree.h"
#include "CollisionSystem.h"
#include "Night.h"
#include "House.h"
#include "Fountain.h"
#include "Backer.h"
#include "trainMob.h"
#include "InDoor.h"
#include "fence.h"
#include "Shop.h"
#include "Mob.h"

#define VM_WIDTH 1280
#define VM_HEIGHT 720
#define GUI_TITLE "Mad Island"
#define MAX_DELAY_NIGHT_SYSTEM 30
#define MAX_NIGHTMOBS 7

class Framework
{
public:
	Framework();
	~Framework();
	void run();

private:
	void quit();
	void update(float frametime);
	void handleEvents();
	void render();
	void CreateAllTrees();
	void calcFrameTime();
	void LoadDayNightImages();
	int RandomFloat(int a, int b);
	int NightSystem();
	sf::RenderWindow *fRenderWindow;
	sf::Event *fMainEvent;
	sf::Clock *fClock;
	sf::Texture *fBackground;
	sf::Sprite *fSprite;
	sf::Texture *houseBackground;
	sf::Sprite *houseSprite;
	sf::Texture *nightTexture[8];
	sf::Sprite *nightSprite[8];
	sf::Clock *nightClock;
	player *Character;
	Tree *tree[MAX_TREES];
	CollisionSystem *collisionSystem;
	House *house;
	Fountain *fountain;
	Backer *backer;
	trainMob *trainmob;
	InDoor *inDoor;
	fence *houseFence;
	Shop *shop;
	Mob *nightMobs[MAX_NIGHTMOBS];
	bool	isNight;
	bool	firstNight;
	bool	fRun;
	float	frameTime;
};

