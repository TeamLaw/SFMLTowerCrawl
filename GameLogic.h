#pragma once
#ifndef GAMELOGIC
#define GAMELOGIC

#define _CRT_SECURE_NO_WARNINGS 1
#define invSizeLimit 10
#define merchSizeLimit 10

#include <Windows.h>
#include <math.h>
#include <time.h>
#include <string>

namespace game
{
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
		Entity(std::string name, COORD xy) {};
		~Entity() {};
		std::string name[21];
		COORD coord;
	};

	class Sprite : public Entity
	{

	public:
		Sprite(std::string name, COORD xy , int Health, int MaxHealth, int Damage, int Exp, int Level, int Money)
			:Entity(name, xy) {};
		Sprite()
			:Entity("", COORD{0,0}) {};
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
		Player(std::string name, COORD xy, int Health, int MaxHealth, int Damage, int Exp, int Level, int Money)
			: Sprite(name, xy, Health, MaxHealth, Damage, Exp, Level, Money) {};
		Player()
			: Sprite(" ", COORD{0,0}, 0, 0, 0, 0, 0, 0) {};
		~Player() {};
		//Room * roomLoc;
		int experience;
		Item inventory[invSizeLimit];
		Item * weapon;
		Item * armor;

	};

	//class NPC : public Entity
	//{
	//public:
	//	NPC() {};
	//	~NPC() {};
	//	Item merchandise[merchSizeLimit];
	//};
	class Enemy : public Sprite
	{
	public:
		Enemy(std::string name, COORD xy, int Health, int MaxHealth, int Damage, int Exp, int Level, int Money)
			: Sprite(name, xy, Health, MaxHealth, Damage, Exp, Level, Money) {};

		Enemy()
		: Sprite(" ", COORD{ 0,0 }, 0, 0, 0, 0, 0, 0) {};
		~Enemy() {};
		Item loot;
		int isBoss;//0 = normal enemy, 1 = boss
	};

	//class Room
	//{//One enemy per room
	//public:
	//	Room() {};
	//	~Room() {};
	//	int xSize;
	//	int ySize;
	//	int isPortal;
	//	int entered;
	//	Room * nDoor;
	//	Room * sDoor;
	//	Room * eDoor;
	//	Room * wDoor;
	//	Entity portal;
	//	Enemy enemy;
	//};

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