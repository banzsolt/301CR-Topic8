#pragma once
#include <iostream>
#include <ctime>
#include "playerGameData.h"
#include "playerPreference.h"

using namespace std;

class Player
{
public:

	int	id = 0;
	string name = "";
	time_t dateOfBirth = time(0);
	string country = "";
	string email = "";
	PlayerGameData playerGameData = PlayerGameData();
	PlayerPreference playerPreference = PlayerPreference();

	Player();
	~Player();

};

