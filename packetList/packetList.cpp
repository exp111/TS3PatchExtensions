#include <thread>
#include <chrono>
#include <memory>
#include <iostream>
#include <api/api.h>
#include "packetList.h"
#include "config.h"
#include "QtPacketList.h"

using namespace std;
using namespace std::chrono;
namespace api = wolverindev::ts;

string pluginId;
struct TS3Functions functions{};
struct api::ApiFunctions hook_functions{};

auto packetListHookDeleter = [](api::Hook* instance) {
	if(instance && hook_functions.unregisterHook)
		hook_functions.unregisterHook(instance);
	delete instance;
};
unique_ptr<api::Hook, decltype(packetListHookDeleter)> packetListHook(nullptr, packetListHookDeleter);


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
	return "Hook [packetList]";
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
	return "Lists Packet in a nice gui (r/niceguys)";
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

	if(packetListHook) hook_functions.unregisterHook(packetListHook.get());
	hook_functions = {};
}

int ts3plugin_offersConfigure() {
	return PLUGIN_OFFERS_CONFIGURE_QT_THREAD;
}

void ts3plugin_configure(void* handle, void* qParentWidget)
{
	Q_UNUSED(handle);
	QtPacketList* cfg = new QtPacketList((QWidget*)qParentWidget);
	cfg->setAttribute(Qt::WA_DeleteOnClose);
	cfg->show();
}

void onPacketOut(api::SCHId schId, api::CommandPacket* command, bool &canceled)
{
	string packet = command->data();
	config->packetsOut.push_back(packet.c_str());
}

void onPacketIn(api::SCHId schId, api::CommandPacket* command, bool &canceled)
{
	string packet = command->data();
	config->packetsIn.push_back(packet.c_str());
}

int hook_initialized(const wolverindev::ts::ApiFunctions fn) {
	printf("%s: Hook called me for initialisation!\n", ts3plugin_name());
	hook_functions = fn;

	packetListHook.reset(new api::Hook());
	packetListHook->activated = [](){ return true; };
	packetListHook->on_packet_out = &onPacketOut;
	packetListHook->on_packet_in = &onPacketIn;
	
	hook_functions.registerHook(packetListHook.get());
	return 0;
}

void hook_finalized() {
	printf("%s: Hook called me for finalisation!\n", ts3plugin_name());
	if(packetListHook) hook_functions.unregisterHook(packetListHook.get());
	hook_functions = {};
}