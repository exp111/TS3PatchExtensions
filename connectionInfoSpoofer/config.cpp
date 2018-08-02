#include "config.h"

Config* config = new Config;

string getShitAfterDelim(string line, char delim)
{
	auto findPos = line.find(delim);
	if (findPos == string::npos)
		return line;
	
	return line.substr(findPos + 1);
}

bool Config::readConfig(string dir)
{
	directory = dir;
	/*
	connection_ping=0.000
	...
	*/

	string configFile = this->directory + this->configName;

	ifstream file(configFile);

	if (!file.good() || file.eof())
		return false;

	string line;
	for (int i = 0; i < this->setConnectionInfo.size(); i++)
	{
		getline(file, line);
		this->setConnectionInfo[i].second = getShitAfterDelim(line, '=');
	}
	
	for (int i = 0; i < this->connectionInfoAutoUpdate.size(); i++)
	{
		getline(file, line);
		this->connectionInfoAutoUpdate[i].second = getShitAfterDelim(line, '=');
	}

	return true;
}

bool Config::writeConfig()
{
	if (this->directory.empty())
		return false;

	ofstream file(this->directory + this->configName, ofstream::out | ofstream::trunc);

	for (pair<string, string> pair : this->setConnectionInfo)
		file << pair.first << "=" << pair.second << endl;
	
	for (pair<string, string> pair : this->connectionInfoAutoUpdate)
		file << pair.first << "=" << pair.second << endl;

	file.close();

	return true;
}
