#include <thread>
#include <chrono>
#include <memory>
#include <iostream>
#include <api/api.h>
#include "connectionInfoSpoofer.h"
#include "QtConfig.h"
#include "config.h"

using namespace std;
using namespace std::chrono;
namespace api = wolverindev::ts;

std::string pluginId;
struct TS3Functions functions{};
struct wolverindev::ts::ApiFunctions hook_functions{};

auto badge_hook_deleter = [](api::Hook* instance) {
	if(instance && hook_functions.unregisterHook)
		hook_functions.unregisterHook(instance);
	delete instance;
};
unique_ptr<api::Hook, decltype(badge_hook_deleter)> connectionInfoSpooferHook(nullptr, badge_hook_deleter);


void ts3plugin_freeMemory(void *data) {
	if (data) free(data);
}

void ts3plugin_setFunctionPointers(const struct TS3Functions funcs) {
	functions = funcs;
}

void ts3plugin_registerPluginID(const char *id) {
	pluginId = id;
}

const char *ts3plugin_name() {
	return "Hook [connectionInfoSpoofer]";
}

const char *ts3plugin_version() {
	return "1.0";
}

int ts3plugin_apiVersion() {
	return 22;
}

const char *ts3plugin_author() {
	return "Exp";
}

const char *ts3plugin_description() {
	return "Spoof your Connection Info.";
}

int ts3plugin_init() { 
	printf("%s: Library hook initialized\n", ts3plugin_name());

	//If we get initialized after the hook we dont recive the hook_initialized event so we have to notify the hook that we're alive!
	//Defined within the API
	trigger_plugin_loaded();

	char configPath[512];
	functions.getConfigPath(configPath, 512);

	config->readConfig(string(configPath) + "plugins/connectionInfoSpoofer/");
	return 0;
}

void ts3plugin_shutdown() {
	printf("%s: Library hook deinitialized\n", ts3plugin_name());

	if(connectionInfoSpooferHook) hook_functions.unregisterHook(connectionInfoSpooferHook.get());
	hook_functions = {};
}

int ts3plugin_offersConfigure() {
	return PLUGIN_OFFERS_CONFIGURE_QT_THREAD;
}

void ts3plugin_configure(void* handle, void* qParentWidget)
{
	Q_UNUSED(handle);
	QtConfig* cfg = new QtConfig((QWidget*)qParentWidget);
	cfg->setAttribute(Qt::WA_DeleteOnClose);
	cfg->show();
}

string getOriginalValue(string buffer, string prefix)
{
	size_t findPos = buffer.find(prefix);
	if (findPos == string::npos)
		return "";

	size_t findEndPos = buffer.find(' ', findPos);
	size_t start = findPos + prefix.size() + 1; //+1 cuz we have the =
	size_t count = findEndPos != string::npos ? findEndPos - start : buffer.size() - start;
	return buffer.substr(start, count);
}

bool setConnectionInfo(string &data, bool &canceled)
{
	//setconnectioninfo connection_ping=13.0000 connection_ping_deviation=2.4515 connection_packets_sent_speech=0 
	//connection_packets_sent_keepalive=1816 connection_packets_sent_control=281 connection_bytes_sent_speech=0 
	//connection_bytes_sent_keepalive=76286 connection_bytes_sent_control=18655 connection_packets_received_speech=0 
	//connection_packets_received_keepalive=1816 connection_packets_received_control=277 connection_bytes_received_speech=0 
	//connection_bytes_received_keepalive=74456 connection_bytes_received_control=85931 connection_server2client_packetloss_speech=0.0000 
	//connection_server2client_packetloss_keepalive=0.0000 connection_server2client_packetloss_control=0.0000 connection_server2client_packetloss_total=0.0000 
	//connection_bandwidth_sent_last_second_speech=0 connection_bandwidth_sent_last_second_keepalive=83 connection_bandwidth_sent_last_second_control=472 
	//connection_bandwidth_sent_last_minute_speech=0 connection_bandwidth_sent_last_minute_keepalive=83 connection_bandwidth_sent_last_minute_control=25 
	//connection_bandwidth_received_last_second_speech=0 connection_bandwidth_received_last_second_keepalive=81 
	//connection_bandwidth_received_last_second_control=105 connection_bandwidth_received_last_minute_speech=0 
	//connection_bandwidth_received_last_minute_keepalive=81 connection_bandwidth_received_last_minute_control=70
	size_t findPos = data.find("setconnectioninfo"); //17 long
	if (findPos == string::npos)
		return false;

	if (config->blockSetConnectionInfo)
	{
		data = "setconnectioninfo";
		return true;
	}

	stringstream buf;
	buf << "setconnectioninfo";
	for (ConnectionInfo info : config->setConnectionInfo)
	{
		if (info.useOriginal) //do we want the original value?
		{
			string origValue = getOriginalValue(data, info.name);
			if (origValue.size() == 0)
				continue;
			buf << " " << info.name << "=" << origValue;
		}
		else
			buf << " " << info.name << "=" << info.value;
	}
	printf("%s\n%s\n", data.c_str(), buf.str().c_str());

	data = buf.str();

	return true;
}

bool connectionInfoAutoUpdate(string &data, bool &canceled)
{
	//connectioninfoautoupdate connection_server2client_packetloss_speech=0.0000 connection_server2client_packetloss_keepalive=0.0000 
	//connection_server2client_packetloss_control=0.0000 connection_server2client_packetloss_total=0.0000
	size_t findPos = data.find("connectioninfoautoupdate"); //24 long
	if (findPos == string::npos)
		return false;

	if (config->blockConnectionInfoAutoUpdate)
	{
		data = "clientupdate"; //prints error with no parameters
		return true;
	}

	stringstream buf; 
	buf << "connectioninfoautoupdate";
	for (ConnectionInfo info : config->connectionInfoAutoUpdate)
	{
		if (info.useOriginal) //do we want the original value?
		{
			string origValue = getOriginalValue(data, info.name);
			if (origValue.size() == 0)
				continue;
			buf << " " << info.name << "=" << origValue;
		}
		else
			buf << " " << info.name << "=" << info.value;
	}
		

	data = buf.str();
	return true;
}

void onPacketOut(api::SCHId schId, api::CommandPacket* command, bool &canceled)
{
	string buffer = command->data();

	bool changed = setConnectionInfo(buffer, canceled) || connectionInfoAutoUpdate(buffer, canceled);
	
	if (changed)
		command->data(buffer);
}

int hook_initialized(const wolverindev::ts::ApiFunctions fn) {
	printf("%s: Hook called me for initialisation!\n", ts3plugin_name());
	hook_functions = fn;

	connectionInfoSpooferHook.reset(new api::Hook());
	connectionInfoSpooferHook->activated = [](){ return true; };
	connectionInfoSpooferHook->on_packet_out = &onPacketOut;
	
	hook_functions.registerHook(connectionInfoSpooferHook.get());
	return 0;
}

void hook_finalized() {
	printf("%s: Hook called me for finalisation!\n", ts3plugin_name());
	if(connectionInfoSpooferHook) hook_functions.unregisterHook(connectionInfoSpooferHook.get());
	hook_functions = {};
}