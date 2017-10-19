#pragma once
namespace game
{
#ifndef GAMELOGIC
#define GAMELOGIC

#define _CRT_SECURE_NO_WARNINGS 1
#define invSizeLimit 10
#define merchSizeLimit 10
#include "GameLogic111.h"
#include <Windows.h>
#include <math.h>
#include <time.h>

	class Entity;
	class Sprite;
	class Player;
	class Room;
	class Enemy;
	class NPC;

class GameLogic
	{
	public:

		static Player THE_PLAYER;
		static Enemy FightingWith();
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
		static int randomNum(int, int);

		GameLogic();
		~GameLogic();
	};

	class Item
	{
	public:
		Item() {};
		~Item() {};
		char name[100];
		int value;
		int health;
		int maxHealth;
		int damage;
	};


	class Entity
	{
	public:
		Entity() {};
		~Entity() {};
		char marker;
		char name[21];
		COORD coord;
	};

	class Sprite : public Entity
	{

	public:
		Sprite() {};
		~Sprite() {};
		int health;
		int maxHealth;
		int damage;
		int exp;
		int level;
		int money;
	};

	class Player : public Sprite
	{
	public:
		Player() {};
		~Player() {};
		Room * roomLoc;
		int experience;
		Item inventory[invSizeLimit];
		Item * weapon;
		Item * armor;

	};

	class NPC : public Entity
	{
	public:
		NPC() {};
		~NPC() {};
		Item merchandise[merchSizeLimit];
	};
	class Enemy : public Sprite
	{
	public:
		Enemy() {};
		~Enemy() {};
		Item loot;
		int isBoss;//0 = normal enemy, 1 = boss
	};

	class Room
	{//One enemy per room
	public:
		Room() {};
		~Room() {};
		int xSize;
		int ySize;
		int isPortal;
		int entered;
		Room * nDoor;
		Room * sDoor;
		Room * eDoor;
		Room * wDoor;
		Entity portal;
		Enemy enemy;
	};

	//enum to pass player choice , I thought it was less confusing than using ints
	enum PlayerChoice
	{
		Attack,
		Use_Item,
		Wait,
		Cheat,
	};


#endif
}