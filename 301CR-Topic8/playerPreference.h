#pragma once
#include <iostream>

using namespace std;

class PlayerPreference
{
public:

	string language = "";
	int volumeLevel = 0;
	string graphicQuality = "";
	int difficultyLevel = 0;

	PlayerPreference();
	~PlayerPreference();
};

