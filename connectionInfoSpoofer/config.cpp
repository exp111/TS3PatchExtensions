#include "config.h"

Config* config = new Config;

string getShitBeforeDelim(string line, char delim)
{
	size_t findPos = line.find(delim);
	if (findPos == string::npos)
		return line;

	return line.substr(0, findPos);
}

string getShitAfterDelim(string line, char delim)
{
	size_t findPos = line.find(delim);
	if (findPos == string::npos)
		return line;
	
	return line.substr(findPos + 1);
}

int toInt(string s, int ret = 0)
{
	if (s.empty())
		return ret;

	return stoi(s);
}
bool Config::readConfig(string dir)
{
	directory = dir;
	/*
	blocksetconnectioninfo=0
	blocksomeotherstuff=1
	connection_ping=0.000
	...
	*/

	string configFile = this->directory + this->configName;

	ifstream file(configFile);

	if (!file.good() || file.eof())
		return false;

	string line;
	map<string, string> options;

	while (getline(file, line))
	{
		options[getShitBeforeDelim(line, '=')] = getShitAfterDelim(line, '=');
	}

	this->blockSetConnectionInfo = toInt(options["blockSetConnectionInfo"], blockSetConnectionInfo);
	this->blockConnectionInfoAutoUpdate = toInt(options["blockConnectionInfoAutoUpdate"], blockSetConnectionInfo);

	for (int i = 0; i < this->setConnectionInfo.size(); i++)
	{
		string line = options[this->setConnectionInfo[i].name];
		if (line.empty())
			continue;
		this->setConnectionInfo[i].value = getShitBeforeDelim(line, ',');
		this->setConnectionInfo[i].useOriginal = toInt(getShitAfterDelim(line, ','), this->setConnectionInfo[i].useOriginal);
	}
	for (int i = 0; i < this->connectionInfoAutoUpdate.size(); i++)
	{
		string line = options[this->connectionInfoAutoUpdate[i].name];
		if (line.empty())
			continue;
		this->connectionInfoAutoUpdate[i].value = getShitBeforeDelim(line, ',');
		this->connectionInfoAutoUpdate[i].useOriginal = toInt(getShitAfterDelim(line, ','), this->setConnectionInfo[i].useOriginal);
	}

	file.close();

	return true;
}

bool Config::writeConfig()
{
	if (this->directory.empty())
		return false;

	ofstream file(this->directory + this->configName, ofstream::out | ofstream::trunc);

	file << "blockSetConnectionInfo=" << int(this->blockSetConnectionInfo) << endl;
	file << "blockConnectionInfoAutoUpdate=" << int(this->blockConnectionInfoAutoUpdate) << endl;

	for (ConnectionInfo info : this->setConnectionInfo)
		file << info.name << '=' << info.value << ',' << info.useOriginal << endl;
	
	for (ConnectionInfo info : this->connectionInfoAutoUpdate)
		file << info.name << '=' << info.value << ',' << info.useOriginal << endl;

	file.close();

	return true;
}
