#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

class Config
{
public:
	Config() { };
	~Config() { };

	string directory;
	string configName = "config.ini";
	
	bool blockSetConnectionInfo = false;
	bool blockConnectionInfoAutoUpdate = false;
	
	vector<pair<string, string>> setConnectionInfo =
	{
		{"connection_ping","0.0000"},
		{"connection_ping_deviation","0"},
		{"connection_packets_sent_speech","0"},
		{"connection_packets_sent_keepalive","0"},
		{"connection_packets_sent_control","0"},
		{"connection_bytes_sent_speech","0"},
		{"connection_bytes_sent_keepalive","0"},
		{"connection_bytes_sent_control","0"},
		{"connection_packets_received_speech","0"},
		{"connection_packets_received_keepalive","0"},
		{"connection_packets_received_control","0"},
		{"connection_bytes_received_speech","0"},
		{"connection_bytes_received_keepalive","0"},
		{"connection_bytes_received_control","0"},
		{"connection_server2client_packetloss_speech","0"},
		{"connection_server2client_packetloss_keepalive","0"},
		{"connection_server2client_packetloss_control","0"},
		{"connection_server2client_packetloss_total","0"},
		{"connection_bandwidth_sent_last_second_speech","0"},
		{"connection_bandwidth_sent_last_second_keepalive","0"},
		{"connection_bandwidth_sent_last_second_control","0"},
		{"connection_bandwidth_sent_last_minute_speech","0"},
		{"connection_bandwidth_sent_last_minute_keepalive","0"},
		{"connection_bandwidth_sent_last_minute_control","0"},
		{"connection_bandwidth_received_last_second_speech","0"},
		{"connection_bandwidth_received_last_second_keepalive","0"},
		{"connection_bandwidth_received_last_second_control","0"},
		{"connection_bandwidth_received_last_minute_speech","0"},
		{"connection_bandwidth_received_last_minute_keepalive","0"},
		{"connection_bandwidth_received_last_minute_control","0"}
	};
	vector<pair<string, string>> connectionInfoAutoUpdate = 
	{	{"connection_server2client_packetloss_speech",	"0.0000"},
		{"connection_server2client_packetloss_keepalive","0.0000"},
		{"connection_server2client_packetloss_control",	"0.0000"},
		{"connection_server2client_packetloss_total",	"0.0000" }};

	bool readConfig(string directory);
	bool readCSV(string directory);
	void readLine(vector<string> results);
	bool writeConfig();
};

extern Config* config;