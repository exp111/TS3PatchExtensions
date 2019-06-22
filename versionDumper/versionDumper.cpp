#include <thread>
#include <chrono>
#include <memory>
#include <iostream>
#include <api/api.h>
#include <helpers.h>
#include "versionDumper.h"

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
unique_ptr<api::Hook, decltype(badge_hook_deleter)> dumper_hook(nullptr, badge_hook_deleter);


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
	return "Hook [versionDumper]";
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
	return "Dump your Build Version and Hash";
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

	if(dumper_hook) hook_functions.unregisterHook(dumper_hook.get());
	hook_functions = {};
}

int ts3plugin_offersConfigure() {
	return PLUGIN_OFFERS_NO_CONFIGURE;
}

string unescapeString(string in) {
	size_t index = 0;
	while (index < in.length()) {
		if (in[index] == '\\') {
			if (in.length() <= index + 1) break;
			char replace = 0;

			switch (in[index + 1]) {
			case 's': replace = ' '; break;
			case '/': replace = '/'; break;
			case 'p': replace = '|'; break;
			case 'b': replace = '\b'; break;
			case 'f': replace = '\f'; break;
			case 'n': replace = '\n'; break;
			case 'r': replace = '\r'; break;
			case 't': replace = '\t'; break;
			case 'a': replace = '\x07'; break;
			case 'v': replace = '\x0B'; break;
			case '\\': replace = '\\'; break;
			default:
				replace = '\x00'; break;
			}
			if (replace != 0x00)
				in.replace(index, 2, string(&replace, 1));
		}
		index++;
	}
	return in;
}

void onPacketOut(api::SCHId schId, api::CommandPacket* command, bool &canceled)
{
	//clientinit client_nickname=Exp\s[Testing] client_version=3.1.8\s[Build:\s1516614607] client_platform=Windows client_input_hardware=1 client_output_hardware=1 client_default_channel client_default_channel_password client_server_password client_meta_data client_version_sign=gDEgQf\/BiOQZdAheKccM1XWcMUj2OUQqt75oFuvF2c0MQMXyv88cZQdUuckKbcBRp7RpmLInto4PIgd7mPO7BQ== client_key_offset=12942926 client_nickname_phonetic client_default_token client_badges=Overwolf=0 hwid=hwidhere
	string buffer = command->data();
	if (buffer.find("clientinit ") == string::npos)
		return;

	string version = parseField(buffer, "client_version");
	if (!version.empty())
	{
		string message = "Version: " + unescapeString(version);
		functions.printMessageToCurrentTab(message.c_str());
	}
	
	string clientHash = parseField(buffer, "client_version_sign");
	if (!version.empty())
	{
		string message = "Hash: " + unescapeString(clientHash);
		functions.printMessageToCurrentTab(message.c_str());
	}
}

int hook_initialized(const wolverindev::ts::ApiFunctions fn) {
	printf("%s: Hook called me for initialisation!\n", ts3plugin_name());
	hook_functions = fn;

	dumper_hook.reset(new api::Hook());
	dumper_hook->activated = [](){ return true; };
	dumper_hook->on_packet_out = &onPacketOut;
	
	hook_functions.registerHook(dumper_hook.get());
	return 0;
}

void hook_finalized() {
	printf("%s: Hook called me for finalisation!\n", ts3plugin_name());
	if(dumper_hook) hook_functions.unregisterHook(dumper_hook.get());
	hook_functions = {};
}