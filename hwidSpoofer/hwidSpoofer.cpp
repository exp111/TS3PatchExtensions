#include <thread>
#include <chrono>
#include <memory>
#include <iostream>
#include <api/api.h>
#include <algorithm>
#include <helpers.h>
#include "hwidSpoofer.h"

using namespace std;
using namespace std::chrono;
namespace api = wolverindev::ts;

string pluginId;
string originalHWID;
string lastHWID;
struct TS3Functions functions{};
struct wolverindev::ts::ApiFunctions hook_functions{};

auto badge_hook_deleter = [](api::Hook* instance) {
	if(instance && hook_functions.unregisterHook)
		hook_functions.unregisterHook(instance);
	delete instance;
};
unique_ptr<api::Hook, decltype(badge_hook_deleter)> hwidSpooferHook(nullptr, badge_hook_deleter);


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
	return "Hook [hwidSpoofer]";
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
	return "Spoof your Hardware ID";
}

int ts3plugin_init() { 
	printf("%s: Library hook initialized\n", ts3plugin_name());

	//If we get initialized after the hook we dont recive the hook_initialized event so we have to notify the hook that we're alive!
	//Defined within the API
	trigger_plugin_loaded();
	return 0;
}

void ts3plugin_shutdown() {
	printf("%s: Library hook deinitialized\n", ts3plugin_name());

	if(hwidSpooferHook) hook_functions.unregisterHook(hwidSpooferHook.get());
	hook_functions = {};
}

int ts3plugin_offersConfigure() {
	return PLUGIN_OFFERS_CONFIGURE_NEW_THREAD;
}

void ts3plugin_configure(void* handle, void* qParentWidget)
{
	functions.printMessageToCurrentTab(("Last HWID: " + lastHWID).c_str());
}

string randomString(size_t length) //https://stackoverflow.com/a/12468109
{
	auto randchar = []() -> char
	{
		const char charset[] =
			"0123456789"
			"abcdefghijklmnopqrstuvwxyz";
		const size_t max_index = (sizeof(charset) - 1);
		return charset[rand() % max_index];
	};
	string str(length, 0);
	generate_n(str.begin(), length, randchar);
	return str;
}

string getRandomHWID()
{
	return randomString(32) + "," + randomString(32);
}

void onPacketOut(api::SCHId schId, api::CommandPacket* command, bool &canceled)
{
	//clientinit ... hwid=fuck
	string buffer = command->data();
	if (buffer.find("clientinit ") != 0)
		return;

	if (buffer.find("hwid") == string::npos)
		return;
	string origHWID = parseField(buffer, "hwid");
	if (originalHWID.empty())
	{
		if (origHWID.empty())
			originalHWID = "nohwid";
		else
			originalHWID = origHWID;
	}
	else if (originalHWID != origHWID) //we need to check if we've already changed it cuz we else it will crash
		return;
	
	lastHWID = getRandomHWID();
	buffer = setField(buffer, "hwid", lastHWID);
	command->data(buffer);
}

int hook_initialized(const wolverindev::ts::ApiFunctions fn) {
	printf("%s: Hook called me for initialisation!\n", ts3plugin_name());
	hook_functions = fn;

	hwidSpooferHook.reset(new api::Hook());
	hwidSpooferHook->activated = [](){ return true; };
	hwidSpooferHook->on_packet_out = &onPacketOut;
	hwidSpooferHook->weight = []() { return 1; };
	
	hook_functions.registerHook(hwidSpooferHook.get());
	return 0;
}

void hook_finalized() {
	printf("%s: Hook called me for finalisation!\n", ts3plugin_name());
	if(hwidSpooferHook) hook_functions.unregisterHook(hwidSpooferHook.get());
	hook_functions = {};
}