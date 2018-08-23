#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <tuple>
#include <map>
using namespace std;

struct ConnectionInfo
{
	string name;
	string value = "0";
	bool useOriginal = true;

};

class Config
{
public:
	Config() { };
	~Config() { };

	string directory;
	string configName = "config.ini";
	
	bool blockSetConnectionInfo = false;
	bool blockConnectionInfoAutoUpdate = false;
	
	vector<ConnectionInfo> setConnectionInfo =
	{
		{"connection_ping","0.0000", true},
		{"connection_ping_deviation","0", true},
		{"connection_packets_sent_speech","0", true},
		{"connection_packets_sent_keepalive","0", true},
		{"connection_packets_sent_control","0", true},
		{"connection_bytes_sent_speech","0", true},
		{"connection_bytes_sent_keepalive","0", true},
		{"connection_bytes_sent_control","0", true},
		{"connection_packets_received_speech","0", true},
		{"connection_packets_received_keepalive","0", true},
		{"connection_packets_received_control","0", true},
		{"connection_bytes_received_speech","0", true},
		{"connection_bytes_received_keepalive","0", true},
		{"connection_bytes_received_control","0", true},
		{"connection_server2client_packetloss_speech","0", true},
		{"connection_server2client_packetloss_keepalive","0", true},
		{"connection_server2client_packetloss_control","0", true},
		{"connection_server2client_packetloss_total","0", true},
		{"connection_bandwidth_sent_last_second_speech","0", true},
		{"connection_bandwidth_sent_last_second_keepalive","0", true},
		{"connection_bandwidth_sent_last_second_control","0", true},
		{"connection_bandwidth_sent_last_minute_speech","0", true},
		{"connection_bandwidth_sent_last_minute_keepalive","0", true},
		{"connection_bandwidth_sent_last_minute_control","0", true},
		{"connection_bandwidth_received_last_second_speech","0", true},
		{"connection_bandwidth_received_last_second_keepalive","0", true},
		{"connection_bandwidth_received_last_second_control","0", true},
		{"connection_bandwidth_received_last_minute_speech","0", true},
		{"connection_bandwidth_received_last_minute_keepalive","0", true},
		{"connection_bandwidth_received_last_minute_control","0", true}
	};
	vector<ConnectionInfo> connectionInfoAutoUpdate =
	{	{"connection_server2client_packetloss_speech",	"0.0000", true},
		{"connection_server2client_packetloss_keepalive","0.0000", true},
		{"connection_server2client_packetloss_control",	"0.0000", true},
		{"connection_server2client_packetloss_total",	"0.0000", true}
	};

	bool readConfig(string directory);
	bool writeConfig();
};

extern Config* config;