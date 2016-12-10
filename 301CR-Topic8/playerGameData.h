#pragma once
#include <list>

using namespace std;

class PlayerGameData
{
public:

	list<int> scoreInLevels;
	int currentLevel = 0;
	int remainingLives = 0;
	int bulletsCount = 0;
	int maxLevelReached = 0;

	PlayerGameData();
	~PlayerGameData();
};

