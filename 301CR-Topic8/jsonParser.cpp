#include "stdafx.h"
#include "jsonParser.h"
#include <sstream>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

using namespace std;

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

Player JsonParser::ReadFromFile(string filename)
{
	// Short alias for this namespace
	namespace pt = boost::property_tree;

	// Create a root
	pt::ptree root;
	pt::read_json(filename, root);

	Player result = Player();

	result.id = root.get<int>("id", 0);
	result.name = root.get<string>("name", "");
	int dobHelper = root.get<int>("dateOfBirth", 0);
	time_t dob = dobHelper;
	result.dateOfBirth = time(&dob);
	result.country = root.get<string>("country", "");
	result.email = root.get<string>("email", "");

	pt::ptree gameData;
	pt::read_json(filename, gameData);	
	result.playerGameData.currentLevel = gameData.get<int>("currentLevel", 0);
	result.playerGameData.remainingLives = gameData.get<int>("remainingLives", 0);
	result.playerGameData.bulletsCount = gameData.get<int>("bulletsCount", 0);
	result.playerGameData.maxLevelReached = gameData.get<int>("maxLevelReached", 0);

	pt::ptree playerPreference;
	pt::read_json(filename, playerPreference);
	result.playerPreference.language = playerPreference.get<string>("language", "");
	result.playerPreference.volumeLevel = playerPreference.get<int>("volumeLevel", 0);
	result.playerPreference.graphicQuality = playerPreference.get<string>("graphicQuality", "");
	result.playerPreference.difficultyLevel = playerPreference.get<int>("difficultyLevel", 0);	

	return result;
}


JsonParser::~JsonParser()
{
}
