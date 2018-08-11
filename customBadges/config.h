#pragma once
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <tuple>
using namespace std;

class Config
{
public:
	Config() { };
	~Config() { };

	bool overwolfBadge = false;
	vector<string> badges = { "94ec66de-5940-4e38-b002-970df0cf6c94" };
	vector<int> badgeIDs = { 3 };
	string directory = "";
	string configName = "config.ini";
	string csvName = "badges.csv";

	unsigned badgeCount = 0;
	//uid,name,description,filename
	vector<tuple<string, string, string, string>> allBadges;

	void readCSVLine(vector<string> results);
	bool readCSV(string directory);
	void readConfigLine(vector<string> results);
	bool readConfig(string dir);
	bool writeConfig();
	string buildBadges();
	int findBadgeID(string GUID);
};

extern Config* config;