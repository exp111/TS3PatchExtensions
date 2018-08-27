#pragma once
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <sstream>
using namespace std;

class Config
{
public:
	Config() { };
	~Config() { };

	string hostMessage = "";
	int hostMode = 2;
};

extern Config* config;