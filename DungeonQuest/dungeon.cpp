#include "dungeon.h"

/*
	Create a local variable that is equal to 1 to 4
	If it is equal to a 1 then a monster appeared
*/
bool monsterAppeared()
{
	int appeared = rand() % 4 + 1;

	return appeared > 1;
}

/*
	Create a local variable that is equal to 10-100
	This is a monsters randomly generated health
*/
int generateMonsterHealth()
{
	int health = rand() % 100 + 10;

	return health;
}

/*
	Create a local variable that is equal to 10-100
	This is a monsters randomly generated attack
*/
int generateMonsterAttack()
{
	int attack = rand() % 50 + 10;

	return attack;
}

int simulateFight(int* health, int* monsterHealth, int monsterAttack, const int BASE_DAMAGE)
{
	std::cout << "You hit the monster with your dagger for " << BASE_DAMAGE << " damage." << std::endl;
	// deal damage equal to the players base damage to the monster 
	*monsterHealth -= BASE_DAMAGE;

	// if the monster dies, return 0 for success
	if (*monsterHealth <= 0)
	{
		return 0;
	}

	std::cout << "The monster has " << *monsterHealth << " life left." << std::endl;

	std::cout << "The monster hits you for " << monsterAttack << " damage." << std::endl;
	// deal damage to the player equal to the monsters randomly generated attack
	*health -= monsterAttack;

	// if the player dies, return 1 for defeat
	if (*health <= 0)
	{
		return 1;
	}

	std::cout << "You have " << *health << " life left." << std::endl;

	// return 2 to continue the fight
	return 2 ;
}

/*
	Create an array of possible loot
	Generate a random number from 0 to the array size
	Then randomly pick a piece of loot at the index of the random number
*/
// saving for final project
//std::string generateLoot()
//{
//	std::string test[5] = {"sword", "armor", "torch", "shield", "axe"};
//	int index = rand() % test->size() - 1;
//
//	return test[index];
//}
