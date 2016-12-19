#include "stdafx.h"
#include "jsonParser.h"
#include <sstream>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

using namespace std;
// Short alias for this namespace
//Refference: http://zenol.fr/blog/boost-property-tree/en.html
namespace pt = boost::property_tree;

JsonParser::JsonParser()
{
}

void JsonParser::WriteToFile(string filename, Player player)
{
	//ofstream myfile;
	//myfile.open(filename);

	pt::ptree root;

	root.put("id", player.id);
	root.put("name", player.name);
	root.put("dateOfBirth", player.dateOfBirth);
	root.put("country", player.country);
	root.put("email", player.email);

	pt::ptree playerGameData;
	// Add a levelScores
	pt::ptree levelScores;
	for (auto &score : player.playerGameData.scoreInLevels)
	{
		// Create an unnamed node containing the value
		pt::ptree fruit_node;
		fruit_node.put("", score);

		// Add this node to the list.
		levelScores.push_back(std::make_pair("", fruit_node));
	}
	playerGameData.add_child("scoreInLevels", levelScores);
	playerGameData.put("currentLevel", player.playerGameData.currentLevel);
	playerGameData.put("remainingLives", player.playerGameData.remainingLives);
	playerGameData.put("bulletsCount", player.playerGameData.bulletsCount);
	playerGameData.put("maxLevelReached", player.playerGameData.maxLevelReached);

	root.add_child("gamedata", playerGameData);

	pt::ptree playerPreference;
	playerPreference.put("language", player.playerPreference.language);
	playerPreference.put("volumeLevel", player.playerPreference.volumeLevel);
	playerPreference.put("graphicQuality", player.playerPreference.graphicQuality);
	playerPreference.put("difficultyLevel", player.playerPreference.difficultyLevel);

	root.add_child("preference", playerPreference);


	pt::write_json(std::cout, root);
	pt::write_json(filename, root);

}

Player JsonParser::ReadFromFile(string filename)
{
	// Create a root
	pt::ptree root;
	pt::read_json(filename, root);

	pt::write_json(std::cout, root);

	Player result = Player();

	result.id = root.get<int>("id", 0);
	result.name = root.get<string>("name", "");
	int dobHelper = root.get<int>("dateOfBirth", 0);
	time_t dob = dobHelper;
	result.dateOfBirth = time(&dob);
	result.country = root.get<string>("country", "");
	result.email = root.get<string>("email", "");

	pt::ptree gameData;
	//pt::read_json(filename, gameData);	
	result.playerGameData.currentLevel = root.get<int>("gamedata.currentLevel", 0);
	result.playerGameData.remainingLives = root.get<int>("gamedata.remainingLives", 0);
	result.playerGameData.bulletsCount = root.get<int>("gamedata.bulletsCount", 0);
	result.playerGameData.maxLevelReached = root.get<int>("gamedata.maxLevelReached", 0);

	for (pt::ptree::value_type &score : root.get_child("gamedata.scoreInLevels"))
	{
		result.playerGameData.scoreInLevels.push_back(stoi(score.second.data()));
	}


	pt::ptree playerPreference;
	pt::read_json(filename, playerPreference);
	result.playerPreference.language = root.get<string>("preference.language", "");
	result.playerPreference.volumeLevel = root.get<int>("preference.volumeLevel", 0);
	result.playerPreference.graphicQuality = root.get<string>("preference.graphicQuality", "");
	result.playerPreference.difficultyLevel = root.get<int>("preference.difficultyLevel", 0);

	return result;
}


JsonParser::~JsonParser()
{
}
