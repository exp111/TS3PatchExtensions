#include <thread>
#include <chrono>
#include <memory>
#include <iostream>
#include <api/api.h>
#include "clientLeftViewFix.h"

using namespace std;
using namespace std::chrono;
namespace api = wolverindev::ts;

std::string pluginId;
struct TS3Functions functions{};
struct wolverindev::ts::ApiFunctions hook_functions{};

auto local_hook_deleter = [](api::Hook* instance) {
	if(instance && hook_functions.unregisterHook)
		hook_functions.unregisterHook(instance);
	delete instance;
};
unique_ptr<api::Hook, decltype(local_hook_deleter)> local_hook(nullptr, local_hook_deleter);

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
	return "Hook [clientLeftViewFix]";
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
	return "Fixes crash if the client receives a clientleft packet with a invalid clid";
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

	hook_functions = {};
}

int ts3plugin_offersConfigure()
{
	return PLUGIN_OFFERS_NO_CONFIGURE;
}

int ts3plugin_requestAutoload() {
	return 0;
}

void onPacketIn(api::SCHId schId, api::CommandPacket* command, bool &canceled)
{
	// notifyclientleftview ... clid=
	string cmd = command->data();
	if (cmd.substr(0, 21) != "notifyclientleftview ")
		return;

	int find = cmd.find("clid=");
	if (find == string::npos)
		return;

	int after = cmd.find(' ');
	int end = after == string::npos ? cmd.length() - 1 : after;
	find += 5;
	string id = cmd.substr(find, end - find);

	int clid = stoi(id);
	
	uint64 channel = 0;

	unsigned err = functions.getChannelOfClient(schId, clid, &channel);
	if (err != 0)
	{
		canceled = true;
	}
}

int hook_initialized(const wolverindev::ts::ApiFunctions fn) {
	printf("%s: Hook called me for initialisation!\n", ts3plugin_name());
	hook_functions = fn;

	local_hook.reset(new api::Hook());
	local_hook->activated = []() { return true; };
	local_hook->on_packet_in = &onPacketIn;

	hook_functions.registerHook(local_hook.get());
	return 0;
}

void hook_finalized() {
	printf("$s: Hook called me for finalisation!\n", ts3plugin_name());
	hook_functions = {};
}