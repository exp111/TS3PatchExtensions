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
	// This checks for a trailing comma with no data after it.
	if (!lineStream && cell.empty())
	{
		// If there was a trailing comma then add an empty element.
		result.push_back("");
	}
	return result;
}

string getShitAfterDelim(string line, char delim)
{
	auto findPos = line.find(delim);
	if (findPos == string::npos)
		return line;
	
	return line.substr(findPos + 1);
}

bool Config::readConfig()
{
	/*
	OS=iOS
	Version=3.0.11 [Build: 1374563791]
	VersionHash=hQCwiLP5f4GIcDG5KQ1T+CNFGqRxyw5MXCHE8KjWRIgkjCuGSryK4vpPy70EURH3blQ8TKrax8BEorHlpnpdAQ==
	*/

	string configFile = this->directory + configName;

	ifstream file(configFile);

	if (!file.good() || file.eof())
		return false;

	string line;
	getline(file, line);
	OS = getShitAfterDelim(line, '='); //OS
	getline(file, line);
	version = getShitAfterDelim(line, '='); //version
	getline(file, line);
	versionHash = getShitAfterDelim(line, '='); //versionHash

	return true;
}

bool Config::readCSV()
{
	string csvFilePath = this->directory + csvName;
	
	ifstream file(csvFilePath);

	if (!file.good())
		return false;

	string line;
	getline(file, line); //skip the first line
	while (!file.eof())
		readLine(getNextLineAndSplitIntoTokens(file));

	file.close();

	return this->foundCSV = true;
}

void Config::readLine(vector<string> results)
{
	//channel,version,platform,hash
	if (find(OSList.begin(), OSList.end(), results[2]) == OSList.end())
		OSList.push_back(results[2]);

	pair<string, string> pair = { results[1], results[3] };
	versionList[results[2]].push_back(pair);
}

bool Config::writeConfig()
{
	if (directory.empty())
		return false;

	ofstream file(directory + configName, ofstream::out | ofstream::trunc);

	file << "OS=" << OS << endl;
	file << "version=" << version << endl;
	file << "versionHash=" << versionHash << endl;

	file.close();

	return true;
}
