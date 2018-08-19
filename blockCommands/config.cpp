#include "config.h"

Config* config = new Config;

vector<string> getNextLineAndSplitIntoTokens(istream& str)
{
	vector<std::string>   result;
	string                line;
	getline(str, line);

	stringstream          lineStream(line);
	string                cell;

	while (getline(lineStream, cell, ','))
	{
		result.push_back(cell);
	}
	return result;
}

bool Config::readConfig(string dir)
{
	directory = dir;
	/*
	clientmute, clientunmute, ...
	incoming command, ...
	*/

	string configFile = this->directory + this->configName;

	ifstream file(configFile);

	if (!file.good() || file.eof())
		return false;

	this->blockOutgoing = getNextLineAndSplitIntoTokens(file);
	this->blockIncoming = getNextLineAndSplitIntoTokens(file);

	file.close();

	return true;
}

bool Config::writeConfig()
{
	if (this->directory.empty())
		return false;

	ofstream file(this->directory + this->configName, ofstream::out | ofstream::trunc);

	for (string command : this->blockOutgoing)
		file << command << ",";

	file << endl;

	for (string command : this->blockIncoming)
		file << command << ",";

	file.close();

	return true;
}
