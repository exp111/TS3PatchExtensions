#include <thread>
#include <chrono>
#include <memory>
#include <iostream>
#include <api/api.h>
#include "customBadges.h"
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
	return "Hook [customBadges]";
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
	printf("%s: Library hook initialized\n", ts3plugin_name());

	//If we get initialized after the hook we dont recive the hook_initialized event so we have to notify the hook that we're alive!
	//Defined within the API
	trigger_plugin_loaded(); 

	char configPath[512];
	functions.getConfigPath(configPath, 512);

	config->setConfigDirectory(configPath);
	config->setDirectory(string(configPath) + "plugins/customBadges/");
	config->readDatabase();
	config->readConfig();

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

void onPacketOut(api::SCHId schId, api::CommandPacket* command, bool &canceled)
{
	//clientupdate client_badges=overwolf=0:badges=f22c22f1-8e2d-4d99-8de9-f352dc26ac5b return_code=__2_
	string buffer = command->data();
	size_t findPos = buffer.find("clientupdate");
	if (findPos != string::npos)
	{
		size_t clientBadgesPos = buffer.find("client_badges="); //14 long
		if (clientBadgesPos == string::npos)
			return;
		size_t clientBadgesEndPos = buffer.find(' ', clientBadgesPos);
		if (clientBadgesEndPos == string::npos)
			clientBadgesEndPos = buffer.length();

		string overwolfStr = (config->overwolfBadge ? "1" : "0");

		buffer = buffer.substr(0, clientBadgesPos + 14) +
			"overwolf=" + overwolfStr + ":badges=" + config->buildBadges(); //+ 
				 //buffer.substr(clientBadgesEndPos, buffer.length());
		command->data(buffer);
	}
}

bool sendBadgeCommand()
{
	string overwolfStr = (config->overwolfBadge ? "1" : "0");
	string cmd = "clientupdate\\sclient_badges=overwolf=" + overwolfStr +
				 ":badges=" + config->buildBadges();

	//hook_functions.sendCommand(1, cmd); //TODO: Crashes
	return true;
}

int hook_initialized(const wolverindev::ts::ApiFunctions fn) {
	printf("%s: Hook called me for initialisation!\n", ts3plugin_name());
	hook_functions = fn;

	badge_hook.reset(new api::Hook());
	badge_hook->activated = [](){ return true; };
	badge_hook->on_packet_out = &onPacketOut;
	
	hook_functions.registerHook(badge_hook.get());
	return 0;
}

void hook_finalized() {
	printf("%s: Hook called me for finalisation!\n", ts3plugin_name());
	if(badge_hook) hook_functions.unregisterHook(badge_hook.get());
	hook_functions = {};
}