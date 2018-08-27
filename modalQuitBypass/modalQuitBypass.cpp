#include <thread>
#include <chrono>
#include <memory>
#include <iostream>
#include <api/api.h>
#include <helpers.h>
#include "modalQuitBypass.h"
#include "config.h"
#include "QtConfig.h"

using namespace std;
using namespace std::chrono;
namespace api = wolverindev::ts;

string pluginId;
struct TS3Functions functions{};
struct wolverindev::ts::ApiFunctions hook_functions{};

auto modelQuitBypassHookDeleter = [](api::Hook* instance) {
	if(instance && hook_functions.unregisterHook)
		hook_functions.unregisterHook(instance);
	delete instance;
};
unique_ptr<api::Hook, decltype(modelQuitBypassHookDeleter)> modalQuitBypassHook(nullptr, modelQuitBypassHookDeleter);


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
	return "Hook [modalQuitBypass]";
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
	return "Bypass Modal Quit Hostmessages";
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

	if(modalQuitBypassHook) hook_functions.unregisterHook(modalQuitBypassHook.get());
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

void onPacketIn(api::SCHId schId, api::CommandPacket* command, bool &canceled)
{
	//initserver ... virtualserver_hostmessage_mode=3
	string buffer = command->data();

	if (buffer.find("virtualserver_hostmessage_mode=3") == string::npos)
		return;

	buffer = setField(buffer, "virtualserver_hostmessage", config->hostMessage);
	buffer = setField(buffer, "virtualserver_hostmessage_mode", to_string(config->hostMode));

	command->data(buffer);
}

int hook_initialized(const wolverindev::ts::ApiFunctions fn) {
	printf("%s: Hook called me for initialisation!\n", ts3plugin_name());
	hook_functions = fn;

	modalQuitBypassHook.reset(new api::Hook());
	modalQuitBypassHook->activated = [](){ return true; };
	modalQuitBypassHook->on_packet_in = &onPacketIn;
	modalQuitBypassHook->weight = []() { return 1; };
	
	hook_functions.registerHook(modalQuitBypassHook.get());
	return 0;
}

void hook_finalized() {
	printf("%s: Hook called me for finalisation!\n", ts3plugin_name());
	if(modalQuitBypassHook) hook_functions.unregisterHook(modalQuitBypassHook.get());
	hook_functions = {};
}