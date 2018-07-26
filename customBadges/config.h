#pragma once
#include <vector>
using namespace std;

class Config
{
public:
	Config() { };
	~Config() { };

	bool overwolfBadge = false;
	vector<string> badges = { "94ec66de-5940-4e38-b002-970df0cf6c94" };
	vector<int> badgeIDs = { 3 };

	const string badgesGUID[16] = {
		"1cb07348-34a4-4741-b50f-c41e584370f7", //Creator
		"450f81c1-ab41-4211-a338-222fa94ed157", //Creator Bronze
		"c9e97536-5a2d-4c8e-a135-af404587a472", //Creator Silver
		"94ec66de-5940-4e38-b002-970df0cf6c94", //Creator Gold
		"62444179-0d99-42ba-a45c-c6b1557d079a", //GC 2014
		"50bbdbc8-0f2a-46eb-9808-602225b49627", //GC 2016
		"534c9582-ab02-4267-aec6-2d94361daa2a", //GC 2017
		"34dbfa8f-bd27-494c-aa08-a312fc0bb240", //Gaming Hero
		"fa3ece28-64df-431f-b1b3-90844bfdd2d9", //Paris 2014
		"d95f9901-c42d-4bac-8849-7164fd9e2310", //Paris 2016
		"7d9fa2b1-b6fa-47ad-9838-c239a4ddd116", //MIFCOM
		"f81ad44d-e931-47d1-a3ef-5fd160217cf8", //4NET
		"f22c22f1-8e2d-4d99-8de9-f352dc26ac5b", //ROCKETBEANS
		"64221fd1-706c-4bb2-ba55-996c39effa79", //MyTeamSpeak early adopter
		"c3f823eb-5d5c-40f9-9dbd-3437d59a539d",	//MyTeamSpeak new member
		"935e5a2a-954a-44ca-aa7a-55c79285b601" }; //E3 2018

	const string badgesIcons[16] = {
		"addon_author_64",
		"addon_author_bronze_64",
		"addon_author_silver_64",
		"addon_author_gold_64",
		"gamescom_2014_64",
		"gamescom_2016_64",
		"gamescom_2017_64",
		"hero_2017_64",
		"paris_gamesweek_2014_64",
		"paris_gamesweek_2016_64",
		"mifcom_64",
		"4netplayers_64",
		"rbtv_64",
		"ts_early_2018_64",
		"ts_2018_64",
		"e3_2018_64" };

	string buildBadges()
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
};

extern Config* config;