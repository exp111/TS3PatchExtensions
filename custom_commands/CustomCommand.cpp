#include <thread>
#include <chrono>
#include <memory>
#include <iostream>
#include <api/api.h>
#include "CustomCommand.h"

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
	return "Hook [CustomCommand]";
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
	return "A plugin which allows you to send custom command via the chat box";
}

int ts3plugin_init() {
	trigger_plugin_loaded();
	return 0;
}

void ts3plugin_shutdown() { }


bool handleTextMessage(std::string& command);
int hook_initialized(const wolverindev::ts::ApiFunctions fn) {
	hook_functions = fn;

	local_hook_test.reset(new api::Hook());
	local_hook_test->activated = [](){ return true; };
	local_hook_test->on_packet_out = [](api::SCHId schId, api::CommandPacket* command, bool &canceled)-> void {
		auto data = command->data();
		if(data.find("sendtextmessage") == 0) {
			if(handleTextMessage(data)) {
				command->data(data);
			}
		}
	};

	hook_functions.registerHook(local_hook_test.get());
	return 0;
}
extern void hook_finalized() {
	printf("%s: Hook called me for finalisation!\n", ts3plugin_name());
	if(local_hook_test) hook_functions.unregisterHook(local_hook_test.get());
	hook_functions = {};
}

std::string unescapeString(std::string in) {
	size_t index = 0;
	while(index < in.length()){
		if(in[index] == '\\'){
			if(in.length() <= index + 1) break;
			char replace = 0;

			switch (in[index + 1]){
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
			if(replace != 0x00)
				in.replace(index, 2, string(&replace, 1));
		}
		index++;
	}
	return in;
}


bool handleTextMessage(std::string& command) {
	//sendtextmessage targetmode=2 msg=asdasd
	auto index_msg = command.find(" msg=");
	if(index_msg == -1 || (index_msg += strlen(" msg=")) > command.length()) return false;
	
	auto cmd = command.substr(index_msg, command.find(' ', index_msg));
	if(cmd.find('~') != 0) return false;
	
	cmd = unescapeString(cmd.substr(1));
	cout << "Injecting command \"" << cmd << "\"" << endl;
	command = cmd;
	return true;
}