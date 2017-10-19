#include "GameLogic.h"


using namespace game;

Player GameLogic::THE_PLAYER = Player{(std::string) "Player",COORD{0,0} ,0,0,0,0,0,0 };
Room *  GameLogic::delPointers[1000];
int  GameLogic::delCounter;
Room *  GameLogic::floorStart;
Room *  GameLogic::floorEnd;
Player  GameLogic::player;
time_t  GameLogic::t;
int  GameLogic::difficulty;
int  GameLogic::branch;
int  GameLogic::location;

GameLogic::GameLogic()
{

}

Enemy GameLogic::FightingWith()
{
	return Enemy{ "Guy",COORD{0,0},1,1,1,1,1,1 };
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