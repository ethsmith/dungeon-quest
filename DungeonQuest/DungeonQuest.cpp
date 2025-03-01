// DungeonQuest.cpp

// include the header file for function prototypes
#include "dungeon.h"
#include <ctime>

int main()
{
	// seed the random number generator
	srand(static_cast<unsigned int>(time(0)));
	// create a variable for the amount of rooms before the boss
	int rooms = 5;
	// create a variable for the amount of health the player has
	int health = 100;
	// create a pointer variable so that functions can modify health
	int* pHealth = &health;
	// create a constant variable for the amount of base damage the player does
	const int BASE_DAMAGE = 20;

	// print intro
	std::cout << "You have woken up in a dungeon and must defeat the boss to escape." << std::endl;
	std::cout << "You have to get through " << rooms << " rooms in order to get to the boss." << std::endl;

	while (health > 0)
	{
		// print game information
		std::cout << "You have " << health << " health." << std::endl;
		std::cout << rooms << " to go before the boss." << std::endl;
		std::cout << "You can rest (gain +15 health) or move to the next room." << std::endl;
		std::cout << "What do you choose? Type rest or move" << std::endl;

		// create a variable to store the player choice
		std::string choice;
		std::cin >> choice;

		// if the player chose to rest, restore 15 health
		if (choice == "rest") 
		{
			health += 15;
			std::cout << "You now have " << health << " health." << std::endl;
		}
		// if the player chose to move, decrement the amount of rooms to go
		else if (choice == "move")
		{
			rooms--;
		}

		// check if a monster appeared, if so, simulate the fight
		if (monsterAppeared())
		{
			std::cout << "Monster appeared! You must fight it to continue." << std::endl;

			// create variables for the monsters randomly generated health and attack
			int monsterHealth = generateMonsterHealth();
			int monsterAttack = generateMonsterAttack();
			int* pMonsterHealth = &monsterHealth;

			// loop the fight till either the player or the monster dies
			while (true) 
			{
				// create a variable to store the result of the fight
				int result = simulateFight(pHealth, pMonsterHealth, monsterAttack, BASE_DAMAGE);

				// if the result is 0, inform the player of their success
				if (result == 0)
				{
					std::cout << "You defeated the monster!" << std::endl;
					break;
				}
				// if the result is 1, inform the player it is game over
				else if (result == 1)
				{
					std::cout << "You were defeated by the monster... Game Over!" << std::endl;
					break;
				}
				// if the result is 2, inform the player it is their turn again
				else if (result == 2)
				{
					std::cout << "Your turn again!" << std::endl;
				}
			}
		}

		if (rooms == 0) 
		{
			// create variables for the bosses health and attack
			int bossHealth = 200;
			int bossAttack = 100;
			int* pBossHealth = &bossHealth;

			std::cout << "The boss fight has started!" << std::endl;
			std::cout << "Your damage is doubled by a magic spell!" << std::endl;
			
			// loop the fight till either the player or the boss dies
			while (true)
			{
				// create a variable to store the result of the fight
				int result = simulateFight(pHealth, pBossHealth, bossAttack, BASE_DAMAGE * 2);

				// if the result is 0, inform the player of their success
				if (result == 0)
				{
					std::cout << "You defeated the boss!" << std::endl;
					break;
				}
				// if the result is 1, inform the player it is game over
				else if (result == 1)
				{
					std::cout << "You were defeated by the boss... Game Over!" << std::endl;
					break;
				}
				// if the result is 2, inform the player it is their turn again
				else if (result == 2)
				{
					std::cout << "Your turn again!";
				}
			}
		}
	}
}
