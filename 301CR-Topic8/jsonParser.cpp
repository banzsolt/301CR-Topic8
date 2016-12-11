#include "stdafx.h"
#include "jsonParser.h"
#include <sstream>


JsonParser::JsonParser()
{
}

void JsonParser::WriteToFile(string filename, Player player)
{
	ofstream myfile;
	myfile.open(filename);

	myfile << "{\n";
	myfile << "\"id\":" << player.id << ",\n";
	myfile << "\"name\":\"" << player.name << "\",\n";
	myfile << "\"dateOfBirth\":" << player.dateOfBirth << ",\n";
	myfile << "\"country\":\"" << player.country << "\",\n";
	myfile << "\"email\":\"" << player.email << "\",\n";
	myfile << "\"gamedata\": { \n";
		myfile << "\"scoreInLevels\": [ \n";
			int iterator = 0;
			for each (int score in player.playerGameData.scoreInLevels)
			{			
				iterator++;
				if (iterator != player.playerGameData.scoreInLevels.size())
				{
					myfile << score << ",\n";
				}
				else
				{
					myfile << score << "\n";
				}
			}
		myfile << "],\n";
		myfile << "\"currentLevel\": " << player.playerGameData.currentLevel << ",\n";
		myfile << "\"remainingLives\": " << player.playerGameData.remainingLives << ",\n";
		myfile << "\"bulletsCount\": " << player.playerGameData.bulletsCount << ",\n";
		myfile << "\"maxLevelReached\": " << player.playerGameData.maxLevelReached << " \n";
		myfile << "},\n";
	myfile << "\"preference\": { \n";
		myfile << "\"language\":\"" << player.playerPreference.language << "\",\n";
		myfile << "\"volumeLevel\":" << player.playerPreference.volumeLevel << ",\n";
		myfile << "\"graphicQuality\":\"" << player.playerPreference.graphicQuality << "\",\n";
		myfile << "\"difficultyLevel\":" << player.playerPreference.difficultyLevel << "\n";
		myfile << "}\n";
	myfile << "}\n";
	
	myfile.close();

}


JsonParser::~JsonParser()
{
}
