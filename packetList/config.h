#pragma once
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <QString>
using namespace std;

class Config
{
public:
	Config() { };
	~Config() { };

	vector<QString> packetsIn;
	vector<QString> packetsOut;
};

extern Config* config;