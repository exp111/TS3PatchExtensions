#include <thread>
#include <chrono>
#include <memory>
#include <iostream>
#include <api/api.h>
#include "PrintPackets.h"

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
unique_ptr<api::Hook, decltype(local_hook_deleter)> local_hook_test(nullptr, local_hook_deleter);


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
	return "Hook [PrintPackets]";
}

const char *ts3plugin_version() {
	return "1.0";
}

int ts3plugin_apiVersion() {
	return 22;
}

const char *ts3plugin_author() {
	return "WolverinDEV";
}

const char *ts3plugin_description() {
	return "A example plugin which uses the hook api";
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

	if(local_hook_test) hook_functions.unregisterHook(local_hook_test.get());
	hook_functions = {};
}


#define HOSTNAME_BUFFER_LENGTH 20
int hook_initialized(const wolverindev::ts::ApiFunctions fn) {
	printf("%s: Hook called me for initialisation!\n", ts3plugin_name());
	hook_functions = fn;

	local_hook_test.reset(new api::Hook());
	local_hook_test->activated = [](){ return true; };
	local_hook_test->on_packet_out = [](api::SCHId schId, api::CommandPacket* command, bool &canceled)-> void {
		printf("[%02lu][ OUT] (%s:%d)\n", schId, command->data().c_str());
	};
	local_hook_test->on_packet_in = [](api::SCHId schId, api::CommandPacket* command, bool &canceled) {
		printf("[%02lu][ IN] (%s:%d)\n", schId, command->data().c_str());
		
		if(command->data().find("send!") != -1)
			std::thread([schId](){
				hook_functions.sendCommand(schId, "sendtextmessage targetmode=2 msg=LALALA\\sLAND!");
			}).detach();
	};
	
	hook_functions.registerHook(local_hook_test.get());
	return 0;
}

void hook_finalized() {
	printf("$s: Hook called me for finalisation!\n", ts3plugin_name());
	if(local_hook_test) hook_functions.unregisterHook(local_hook_test.get());
	hook_functions = {};
}