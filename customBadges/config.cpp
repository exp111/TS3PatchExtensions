#include "config.h"

Config* config = new Config;

string getShitAfterDelim(string line, char delim)
{
	auto findPos = line.find(delim);
	if (findPos == string::npos)
		return line;

	return line.substr(findPos + 1);
}

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
	// This checks for a trailing comma with no data after it.
	if (!lineStream && cell.empty())
	{
		// If there was a trailing comma then add an empty element.
		result.push_back("");
	}
	return result;
}

void Config::readLine(vector<string> results)
{
	for (string result : results)
	{
		if (result.size() > 1)
		{
			this->badges.push_back(result);
		}
	}
}

bool Config::readConfig(string dir)
{
	this->directory = dir;

	string configFile = this->directory + this->configName;

	ifstream file(configFile);

	if (!file.good() || file.eof())
		return false;

	string line;

	getline(file, line);
	this->overwolfBadge = stoi(getShitAfterDelim(line, '='));

	this->badges.clear();
	readLine(getNextLineAndSplitIntoTokens(file));

	this->badgeIDs.clear();
	for (string badge : this->badges) //add ids from badgeGUIDs
		this->badgeIDs.push_back(findBadgeID(badge));

	return true;
}

bool Config::writeConfig()
{
	if (this->directory.empty())
		return false;

	ofstream file(this->directory + this->configName, ofstream::out | ofstream::trunc);

	file << "overwolfBadge=" << int(this->overwolfBadge) << endl;

	for (string badge : this->badges)
		file << badge << ",";

	file.close();

	return true;
}

string Config::buildBadges()
{
	string badgesString = "";
	for (int i = 0; i < this->badges.size(); i++)
	{
		badgesString += this->badges[i] + ',';
	}
	if (badgesString.size() > 0)
		badgesString.pop_back(); //delete last comma

	return badgesString;
}

int Config::findBadgeID(string GUID)
{
	for (unsigned i = 0; i < config->badgesGUID->size(); i++)
	{
		if (config->badgesGUID[i] == GUID)
			return i;
		else
			continue;
	}
	return -1;
}
