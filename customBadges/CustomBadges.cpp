#include <thread>
#include <chrono>
#include <memory>
#include <iostream>
#include <api/api.h>
#include "CustomBadges.h"

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
unique_ptr<api::Hook, decltype(badge_hook_deleter)> badge_hook(nullptr, badge_hook_deleter);


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
	return "Hook [CustomBadges]";
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
	return "Customize TeamSpeak Badges.";
}

int ts3plugin_init() { 
	printf("Library hook initialized\n");

	//If we get initialized after the hook we dont recive the hook_initialized event so we have to notify the hook that we're alive!
	//Defined within the API
	trigger_plugin_loaded(); 
	return 0;
}

void ts3plugin_shutdown() {
	printf("Library hook deinitialized\n");

	if(badge_hook) hook_functions.unregisterHook(badge_hook.get());
	hook_functions = {};
}

#define HOSTNAME_BUFFER_LENGTH 20

bool overwolf = true;
string badges = "f22c22f1-8e2d-4d99-8de9-f352dc26ac5b, f22c22f1-8e2d-4d99-8de9-f352dc26ac5b";

void onPacketOut(api::SCHId schId, api::CommandPacket* command, bool &canceled)
{
	//clientupdate client_badges=overwolf=0:badges=f22c22f1-8e2d-4d99-8de9-f352dc26ac5b return_code=__2_
	string buffer = command->data();
	size_t findPos = buffer.find("clientupdate");
	if (findPos != string::npos)
	{
		size_t clientBadgesPos = buffer.find("client_badges="); //14 long
		size_t clientBadgesEndPos = buffer.find(' ', clientBadgesPos);
		string overwolfStr = (overwolf ? "1" : "0");
		buffer = buffer.substr(0, clientBadgesPos + 14) + 
				 "overwolf=" + overwolfStr + badges + 
				 buffer.substr(clientBadgesEndPos, buffer.length());
		command->data(buffer);
	}
	printf("Command out: %s\n", command->data().c_str());
}

void onPacketIn(api::SCHId schId, api::CommandPacket* command, bool &canceled)
{
	printf("Command in: %s\n", command->data().c_str());
}


int hook_initialized(const wolverindev::ts::ApiFunctions fn) {
	printf("Hook called me for initialisation!\n");
	hook_functions = fn;

	badge_hook.reset(new api::Hook());
	badge_hook->activated = [](){ return true; };
	badge_hook->on_packet_out = &onPacketOut;
	badge_hook->on_packet_in = &onPacketIn;
	
	hook_functions.registerHook(badge_hook.get());
	return 0;
}

void hook_finalized() {
	printf("Hook called me for finalisation!\n");
	if(badge_hook) hook_functions.unregisterHook(badge_hook.get());
	hook_functions = {};
}