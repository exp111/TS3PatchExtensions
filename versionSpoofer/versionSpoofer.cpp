#include <thread>
#include <chrono>
#include <memory>
#include <iostream>
#include <api/api.h>
#include "versionSpoofer.h"
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
unique_ptr<api::Hook, decltype(badge_hook_deleter)> spoofer_hook(nullptr, badge_hook_deleter);


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
	return "Hook [versionSpoofer]";
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
	return "Spoof your TeamSpeak Version & OS.";
}

int ts3plugin_init() { 
	printf("%s: Library hook initialized\n", ts3plugin_name());

	//If we get initialized after the hook we dont recive the hook_initialized event so we have to notify the hook that we're alive!
	//Defined within the API
	trigger_plugin_loaded();

	char configPath[512];
	functions.getConfigPath(configPath, 512);

	config->readConfig(string(configPath) + "plugins/versionSpoofer/");

	/*config->OSList = { "Windows", "Linux" };
	config->versionList["Windows"] = { {"3.0.11 [Build: 1374563791]", "hQCwiLP5f4GIcDG5KQ1T+CNFGqRxyw5MXCHE8KjWRIgkjCuGSryK4vpPy70EURH3blQ8TKrax8BEorHlpnpdAQ=="},{ "3.0.11 [Build: 1374830986]", "PJvjEuApy2McckLGGnAgw8kB2FE+yb4J/TuUdaLj+x5JVghSBR5tKJDQklLurJrshKynWzYYtokrtgBxTAz5CA==" } };
	config->versionList["Linux"] = { {"3.0.16 [Build: 1407159763]", "8776GitHAgkFPfOLxEh5x+Luuh4NrYPEJUdsUzNKndcAuWMYjwQTZkmeZOeG/swdn/p2Cg2pRfZfsIFSOAUWCQ=="} };
	*/
	return 0;
}

void ts3plugin_shutdown() {
	printf("%s: Library hook deinitialized\n", ts3plugin_name());

	if(spoofer_hook) hook_functions.unregisterHook(spoofer_hook.get());
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

string escape(string toEscape)
{
	string buf = toEscape;
	for (int i = 0; i < buf.size(); i++)
	{
		if (buf[i] == ' ')
		{
			buf[i] = '\\';
			buf.insert(buf.begin() + i + 1, 's');
		}
	}

	return buf;
}

void onPacketOut(api::SCHId schId, api::CommandPacket* command, bool &canceled)
{
	string buffer = command->data();
	size_t find_pos = buffer.find("client_version="); //15 long
	if (find_pos == string::npos)
		return;

	size_t find_pos2 = buffer.find(" client_input_hardware=");
	if (find_pos2 == string::npos)
		return;

	size_t findPos3 = buffer.find(" client_version_sign="); //21 long
	size_t findPos4 = buffer.find(" client_key_offset=");
	string s;
	for (int i = 0; i < find_pos + 15; i++)
		s += buffer.at(i);

	s += escape(config->version) + " client_platform=" + config->OS;
	for (int i = find_pos2; i < findPos3 + 21; i++)
		s += buffer.at(i);

	s += config->versionHash;
	for (int i = findPos4; i < buffer.size(); i++)
		s += buffer.at(i);	
	
	command->data(s);
}

int hook_initialized(const wolverindev::ts::ApiFunctions fn) {
	printf("%s: Hook called me for initialisation!\n", ts3plugin_name());
	hook_functions = fn;

	spoofer_hook.reset(new api::Hook());
	spoofer_hook->activated = [](){ return true; };
	spoofer_hook->on_packet_out = &onPacketOut;
	
	hook_functions.registerHook(spoofer_hook.get());
	return 0;
}

void hook_finalized() {
	printf("%s: Hook called me for finalisation!\n", ts3plugin_name());
	if(spoofer_hook) hook_functions.unregisterHook(spoofer_hook.get());
	hook_functions = {};
}