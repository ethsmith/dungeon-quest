#pragma once
#include <iostream>
#include <string>

// function prototypes
bool monsterAppeared();
int generateMonsterHealth();
int generateMonsterAttack();
int simulateFight(int* health, int* monsterHealth, int monsterAttack, const int BASE_DAMAGE);
//std::string generateLoot();