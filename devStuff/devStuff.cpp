#include <thread>
#include <chrono>
#include <memory>
#include <iostream>
#include <api/api.h>
#include <vector>
#include <helpers.h>
#include "devStuff.h"

using namespace std;
using namespace std::chrono;
namespace api = wolverindev::ts;

string pluginId;
string originalHWID;
struct TS3Functions functions{};
struct wolverindev::ts::ApiFunctions hook_functions{};

auto badge_hook_deleter = [](api::Hook* instance) {
	if(instance && hook_functions.unregisterHook)
		hook_functions.unregisterHook(instance);
	delete instance;
};
unique_ptr<api::Hook, decltype(badge_hook_deleter)> testHook(nullptr, badge_hook_deleter);


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
	return "Hook [devStuff]";
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
	return "Testing some Stuff";
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

	if(testHook) hook_functions.unregisterHook(testHook.get());
	hook_functions = {};
}

int ts3plugin_offersConfigure() {
	return PLUGIN_OFFERS_NO_CONFIGURE;
}

void onPacketOut(api::SCHId schId, api::CommandPacket* command, bool &canceled)
{
	//clientinit ... hwid=fuck
	string buffer = command->data();
	if (buffer.find("clientinit") == string::npos)
		return;

	buffer = setFields(buffer, { "ot", "alpha" }, { "10", "fuck"});
	auto results = parse(buffer);

	for (auto result : results)
		functions.printMessageToCurrentTab((result.first + "=" + result.second).c_str());
}

int hook_initialized(const wolverindev::ts::ApiFunctions fn) {
	printf("%s: Hook called me for initialisation!\n", ts3plugin_name());
	hook_functions = fn;

	testHook.reset(new api::Hook());
	testHook->activated = [](){ return true; };
	testHook->on_packet_out = &onPacketOut;
	
	hook_functions.registerHook(testHook.get());
	return 0;
}

void hook_finalized() {
	printf("%s: Hook called me for finalisation!\n", ts3plugin_name());
	if(testHook) hook_functions.unregisterHook(testHook.get());
	hook_functions = {};
}