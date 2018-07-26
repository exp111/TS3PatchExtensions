#include <thread>
#include <chrono>
#include <memory>
#include <iostream>
#include <api/api.h>
#include "qtTest.h"
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
	return "Hook [qtTest]";
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
	return "Qt GUI Test";
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

	if(badge_hook) hook_functions.unregisterHook(badge_hook.get());
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

#define HOSTNAME_BUFFER_LENGTH 20

void onPacketOut(api::SCHId schId, api::CommandPacket* command, bool &canceled)
{
	printf("Command out: %s\n", command->data().c_str());
}

void onPacketIn(api::SCHId schId, api::CommandPacket* command, bool &canceled)
{
	printf("Command in: %s\n", command->data().c_str());
}


int hook_initialized(const wolverindev::ts::ApiFunctions fn) {
	printf("%s: Hook called me for initialisation!\n", ts3plugin_name());
	hook_functions = fn;

	badge_hook.reset(new api::Hook());
	badge_hook->activated = [](){ return true; };
	badge_hook->on_packet_out = &onPacketOut;
	badge_hook->on_packet_in = &onPacketIn;
	
	hook_functions.registerHook(badge_hook.get());
	return 0;
}

void hook_finalized() {
	printf("%s: Hook called me for finalisation!\n", ts3plugin_name());
	if(badge_hook) hook_functions.unregisterHook(badge_hook.get());
	hook_functions = {};
}