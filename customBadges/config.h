#pragma once
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <QSqlDatabase>
#include <QSqlQuery>
#include "QtDownloader.h"
using namespace std;

struct Badge
{
	Badge(string uid, string name, string desc, string fileName)
	{
		this->uid = uid;
		this->name = name;
		this->description = desc;
		this->fileName = fileName;
	}
	string uid;
	string name;
	string description;
	string fileName;
};

class Config
{
public:
	Config() { };
	~Config() { };

	bool overwolfBadge = false;
	vector<string> badges = { "94ec66de-5940-4e38-b002-970df0cf6c94" };
	vector<int> badgeIDs = { 3 };
	string configDirectory;
	string directory;
	string configName = "config.ini";

	unsigned badgeCount = 0;
	//uid,name,description,filename
	vector<Badge> allBadges;

	void setConfigDirectory(string dir) { this->configDirectory = dir; };
	void setDirectory(string directory) { this->directory = directory; };
	void readCSVLine(vector<string> results);
	bool readDatabase();
	void readConfigLine(vector<string> results);
	bool readConfig();
	bool writeConfig();
	string buildBadges();
	int findBadgeID(string GUID);
	string getIconPath(string iconName, bool largeIcon);
private:
	QtDownloader* downloader = nullptr;
};

extern Config* config;