#pragma once
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <sstream>
#include "QtDownloader.h"
using namespace std;

class Config
{
private:
	QtDownloader* downloader = nullptr;
public:
	Config() { };
	~Config() { };

	string directory;
	string configName = "config.ini";
	string csvName = "versions.csv";
	const char* csvUrl = "https://raw.githubusercontent.com/ReSpeak/tsdeclarations/master/Versions.csv";
	bool foundCSV = false;

	string OS = "iOS";
	string version = "3.?.? [Build: 5680278000]";
	string versionHash = "DX5NIYLvfJEUjuIbCidnoeozxIDRRkpq3I9vVMBmE9L2qnekOoBzSenkzsg2lC9CMv8K5hkEzhr2TYUYSwUXCg==";

	bool useCustomOSVersion = false;
	string customOS = "unknown";
	string customVersion = "unknown";
	string customHash = "unknown";

	vector<string> OSList;
	map<string, vector<pair<string, string>>> versionList;
	//versionList["Windows"] = { {"3.0.11 [Build: 1374563791]", "hQCwiLP5f4GIcDG5KQ1T+CNFGqRxyw5MXCHE8KjWRIgkjCuGSryK4vpPy70EURH3blQ8TKrax8BEorHlpnpdAQ=="}, {"3.0.11 [Build: 1374830986]", "PJvjEuApy2McckLGGnAgw8kB2FE+yb4J/TuUdaLj+x5JVghSBR5tKJDQklLurJrshKynWzYYtokrtgBxTAz5CA=="}, ... }

	void setDirectory(string directory) { this->directory = directory; };
	bool readConfig();
	bool readCSV();
	void readLine(vector<string> results);
	bool writeConfig();
	void getCSV();
};

extern Config* config;