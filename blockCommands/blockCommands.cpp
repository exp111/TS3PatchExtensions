#include <thread>
#include <chrono>
#include <memory>
#include <iostream>
#include <api/api.h>
#include "blockCommands.h"
#include "config.h"
#include "QtConfig.h"

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
unique_ptr<api::Hook, decltype(badge_hook_deleter)> blockCommandsHook(nullptr, badge_hook_deleter);


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
	return "Hook [blockCommands]";
}

const char *ts3plugin_version() {
	return "1.0";
}

int ts3plugin_apiVersion() {
	return 23;
}

const char *ts3plugin_author() {
	return "Exp";
}

const char *ts3plugin_description() {
	return "Block in- and outgoing commands";
}

int ts3plugin_init() { 
	printf("%s: Library hook initialized\n", ts3plugin_name());

	//If we get initialized after the hook we dont recive the hook_initialized event so we have to notify the hook that we're alive!
	//Defined within the API
	trigger_plugin_loaded();

	char configPath[512];
	functions.getConfigPath(configPath, 512);

	config->readConfig(string(configPath) + "plugins/blockCommands/");
	return 0;
}

void ts3plugin_shutdown() {
	printf("%s: Library hook deinitialized\n", ts3plugin_name());

	if(blockCommandsHook) hook_functions.unregisterHook(blockCommandsHook.get());
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

void cancelCommand(api::CommandPacket* command, bool &canceled)
{
	//canceled = true; //ts3patch will set it to "_hook_canceled", but that will send a not implemented error
	command->data("clientupdate");
}

void onPacketOut(api::SCHId schId, api::CommandPacket* command, bool &canceled)
{
	string buffer = command->data();

	for (string cmd : config->blockOutgoing)
		if (buffer.substr(0, cmd.size()) == cmd)
			cancelCommand(command, canceled);
}

void onPacketIn(api::SCHId schId, api::CommandPacket* command, bool &canceled)
{
	string buffer = command->data();

	for (string cmd : config->blockIncoming)
		if (buffer.substr(0, cmd.size()) == cmd)
			canceled = true;
}

int hook_initialized(const wolverindev::ts::ApiFunctions fn) {
	printf("%s: Hook called me for initialisation!\n", ts3plugin_name());
	hook_functions = fn;

	blockCommandsHook.reset(new api::Hook());
	blockCommandsHook->activated = [](){ return true; };
	blockCommandsHook->on_packet_out = &onPacketOut;
	blockCommandsHook->on_packet_in = &onPacketIn;
	
	hook_functions.registerHook(blockCommandsHook.get());
	return 0;
}

void hook_finalized() {
	printf("%s: Hook called me for finalisation!\n", ts3plugin_name());
	if(blockCommandsHook) hook_functions.unregisterHook(blockCommandsHook.get());
	hook_functions = {};
}