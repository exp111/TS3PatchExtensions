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

void Config::readCSVLine(vector<string> results)
{
	//uid,name,description,filename
	if (results.size() < 4)
		return;
	this->allBadges.push_back(Badge(results[0], results[1], results[2], results[3]));
	this->badgeCount++;
}

bool Config::readDatabase()
{
	//https://github.com/Bluscream/pyTSon_plugins/blob/c0c2baa38ba59bfbbb88496b20edcf3fc889e439/include/bluscream.py#L601
	QString filePath = (this->configDirectory + "settings.db").c_str();
	if (!QFile::exists(filePath))
		return false;
	
	QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
	db.setDatabaseName(filePath);

	if (!db.open())
		return false;

	this->badgeCount = 0;
	this->allBadges.clear();

	QSqlQuery query;
	if (!query.exec("SELECT * FROM Badges WHERE key = 'BadgesListData'"))
		return false;
	
	query.next(); //Get to the first record. Should only have one so no need for a loop here
	auto value = query.value("value").toString();
	int next = 12;
	int guid_len = 0; string guid = "";
	int	name_len = 0; string name = "";
	int	url_len = 0; string fileName = "";
	int	desc_len = 0; string desc = "";
	for (int i = 0; i < value.size(); i++)
	{
		if (i == next) //uid
		{
			guid_len = value.at(i).unicode();
			guid = value.mid(i + 1, guid_len).toStdString();
		}
		else if (i == (next + 1 + guid_len + 1)) //name
		{
			name_len = value.at(i).unicode();
			name = value.mid(i + 1, name_len).toStdString();
		}
		else if (i == (next + 1 + guid_len + 1 + name_len + 2)) //url
		{
			url_len = value.at(i).unicode();
			QString url = value.mid(i + 1, url_len);
			fileName = url.mid(url.lastIndexOf('/') + 1).toStdString();
		}
		else if (i == (next + 1 + guid_len + 1 + name_len + 2 + url_len + 2)) //description
		{
			desc_len = value.at(i).unicode();
			desc = value.mid(i + 1, desc_len).toStdString();

			this->allBadges.push_back(Badge(guid, name, desc, fileName));
			this->badgeCount++;

			//TODO: fix this mess (better not search for 0x24 manually cuz it could be somewhere else and we don't know if the uids are always 36 long)
			next = value.indexOf('$', i);//(next + guid_len + 2 + name_len + 2 + url_len + 2 + desc_len + 12);
		}
	}

	return true;
}

void Config::readConfigLine(vector<string> results)
{
	for (string result : results)
	{
		if (result.size() > 1)
		{
			this->badges.push_back(result);
		}
	}
}

bool Config::readConfig()
{
	string configFile = this->directory + this->configName;

	ifstream file(configFile);

	if (!file.good() || file.eof())
		return false;

	string line;

	getline(file, line);
	this->overwolfBadge = stoi(getShitAfterDelim(line, '='));

	this->badges.clear();
	readConfigLine(getNextLineAndSplitIntoTokens(file));

	this->badgeIDs.clear();
	for (string badge : this->badges) //add ids from badgeGUIDs
		this->badgeIDs.push_back(findBadgeID(badge));

	file.close();

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
	for (unsigned i = 0; i < badgeCount; i++)
	{
		if (this->allBadges[i].uid == GUID)
			return i;
		else
			continue;
	}
	return -1;
}

string Config::getIconPath(string iconName, bool largeIcon)
{
	//First try to get from our icons folder
	string filePath = config->directory + "icons/" + iconName;
	filePath += largeIcon ? "_64.png" : ".png";
	if (fstream(filePath.c_str()).good())
		return filePath;

	//Try to get from cache else
	filePath = config->configDirectory + "cache/badges/" + iconName;
	filePath += largeIcon ? "_details.svg" : ".svg";
	if (fstream(filePath.c_str()).good())
		return filePath;

	return config->directory + "icons/placeholder" + (largeIcon ? "_64.png" : ".png"); //if not found use placeholder
}