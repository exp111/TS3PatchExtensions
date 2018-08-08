#include "config.h"

Config* config = new Config;

string getShitAfterDelim(string line, char delim)
{
	size_t findPos = line.find(delim);
	if (findPos == string::npos)
		return line;
	
	return line.substr(findPos + 1);
}

string getShitAfterDelim(string line, char delim, char delim2)
{
	size_t findPos = line.find(delim);
	if (findPos == string::npos)
		return line;

	size_t findPos2 = line.find(delim2, findPos);
	if (findPos2 == string::npos)
		findPos2 = line.size();

	return line.substr(findPos + 1, findPos2 - findPos - 1);
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

	getline(file, line);
	this->blockSetConnectionInfo = stoi(getShitAfterDelim(line, '='));
	getline(file, line);
	this->blockConnectionInfoAutoUpdate = stoi(getShitAfterDelim(line, '='));

	for (int i = 0; i < this->setConnectionInfo.size(); i++)
	{
		getline(file, line);
		get<1>(this->setConnectionInfo[i]) = getShitAfterDelim(line, '=', ',');
		get<2>(this->setConnectionInfo[i]) = stoi(getShitAfterDelim(line, ','));
	}
	
	for (int i = 0; i < this->connectionInfoAutoUpdate.size(); i++)
	{
		getline(file, line);
		get<1>(this->connectionInfoAutoUpdate[i]) = getShitAfterDelim(line, '=', ',');
		get<2>(this->connectionInfoAutoUpdate[i]) = stoi(getShitAfterDelim(line, ','));
	}

	return true;
}

bool Config::writeConfig()
{
	if (this->directory.empty())
		return false;

	ofstream file(this->directory + this->configName, ofstream::out | ofstream::trunc);

	file << "blockSetConnectionInfo=" << int(this->blockSetConnectionInfo) << endl;
	file << "blockConnectionInfoAutoUpdate=" << int(this->blockConnectionInfoAutoUpdate) << endl;

	for (tuple<string, string, bool> tuple : this->setConnectionInfo)
		file << get<0>(tuple) << '=' << get<1>(tuple) << ',' << get<2>(tuple) << endl;
	
	for (tuple<string, string, bool> tuple : this->connectionInfoAutoUpdate)
		file << get<0>(tuple) << '=' << get<1>(tuple) << ',' << get<2>(tuple) << endl;

	file.close();

	return true;
}
