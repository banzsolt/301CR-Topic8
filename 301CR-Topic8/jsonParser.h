#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include "player.h"
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

using namespace std;

class JsonParser
{
public:

	JsonParser();
	void WriteToFile(string filename, Player player);
	Player ReadFromFile(string filename);

	~JsonParser();

};

