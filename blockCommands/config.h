#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <tuple>
using namespace std;

class Config
{
public:
	Config() { };
	~Config() { };

	string directory;
	string configName = "config.ini";
	
	vector<string> blockIncoming;
	vector<string> blockOutgoing;

	bool readConfig(string directory);
	bool writeConfig();
};

extern Config* config;