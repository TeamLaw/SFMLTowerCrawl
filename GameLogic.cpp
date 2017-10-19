#include "GameLogic.h"


using namespace game;


Player GameLogic::THE_PLAYER = Player{};
static Room * delPointers[1000];
static int delCounter;
static Room * floorStart;
static Room * floorEnd;
static Player player;
static NPC shopkeeper;
static NPC innkeeper;
static NPC blacksmith;
static time_t t;
static int difficulty;
static int branch;
static int location;

GameLogic::GameLogic()
{
}

Enemy GameLogic::FightingWith()
{
	return Enemy{};
}

GameLogic::~GameLogic()
{
}

int GameLogic::randomNum(int low, int high)
{
	int r;

	r = rand() % (high - low) + low;
	return r;
}