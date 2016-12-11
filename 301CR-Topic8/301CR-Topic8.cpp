// 301CR-Topic8.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include "jsonParser.h"
#include "player.h"

using namespace std;

int main()
{
	
	string value = "";
	JsonParser jsonParser = JsonParser();


	while (value != "0")
	{
		list<int> scoreInLevels = { 10, 11, 12, 12, 10, 10, 10 };
		Player player = Player();
		player.name = "banzsolt";
		player.id = 1;
		player.dateOfBirth = time(0);
		player.country = "UK";
		player.email = "banzsolt94@gmail.com";
		player.playerGameData.bulletsCount = 3424;
		player.playerGameData.scoreInLevels = scoreInLevels;
		player.playerGameData.currentLevel = 5;
		player.playerGameData.remainingLives = 2;
		player.playerGameData.maxLevelReached = 7;
		player.playerPreference.language = "english";
		player.playerPreference.volumeLevel = 2;
		player.playerPreference.graphicQuality = "1920x1080";
		player.playerPreference.difficultyLevel = 2;

		jsonParser.WriteToFile("exmaple.txt", player);

		cout << "Please, enter your full name: ";
		getline(cin, value);
		cout << value;
		getline(std::cin, value);
	}

	

    return 0;
}

