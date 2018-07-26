#pragma once

class Config
{
public:
	Config() { };
	~Config() { };

	bool testBool = false;
};

extern Config* config;