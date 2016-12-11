#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include "player.h"

using namespace std;

class JsonParser
{
public:

	JsonParser();
	void WriteToFile(string filename, Player player);

	~JsonParser();

};

