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
		string line = options[get<0>(this->setConnectionInfo[i])];
		if (line.empty())
			continue;
		get<1>(this->setConnectionInfo[i]) = getShitBeforeDelim(line, ',');
		get<2>(this->setConnectionInfo[i]) = toInt(getShitAfterDelim(line, ','), get<2>(this->setConnectionInfo[i]));
	}
	for (int i = 0; i < this->connectionInfoAutoUpdate.size(); i++)
	{
		string line = options[get<0>(this->connectionInfoAutoUpdate[i])];
		if (line.empty())
			continue;
		get<1>(this->connectionInfoAutoUpdate[i]) = getShitBeforeDelim(line, ',');
		get<2>(this->connectionInfoAutoUpdate[i]) = toInt(getShitAfterDelim(line, ','), get<2>(this->setConnectionInfo[i]));
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

	for (tuple<string, string, bool> tuple : this->setConnectionInfo)
		file << get<0>(tuple) << '=' << get<1>(tuple) << ',' << get<2>(tuple) << endl;
	
	for (tuple<string, string, bool> tuple : this->connectionInfoAutoUpdate)
		file << get<0>(tuple) << '=' << get<1>(tuple) << ',' << get<2>(tuple) << endl;

	file.close();

	return true;
}
