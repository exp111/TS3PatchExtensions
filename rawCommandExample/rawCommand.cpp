#include <thread>
#include <chrono>
#include <memory>
#include <iostream>
#include <api/api.h>
#include "rawCommand.h"

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
	return "Hook [rawCommand]";
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

	hook_functions = {};
}

int ts3plugin_offersConfigure()
{
	return PLUGIN_OFFERS_NO_CONFIGURE;
}
const char* ts3plugin_commandKeyword() {
	return "rawCommandTest";
}
const char* ts3plugin_infoTitle() {
	return "Raw Command Test";
}

int ts3plugin_requestAutoload() {
	return 0;
}

static struct PluginMenuItem* createMenuItem(enum PluginMenuType type, int id, const char* text, const char* icon) {
	struct PluginMenuItem* menuItem = (struct PluginMenuItem*)malloc(sizeof(struct PluginMenuItem));
	menuItem->type = type;
	menuItem->id = id;
	strcpy_s(menuItem->text, PLUGIN_MENU_BUFSZ, text);
	strcpy_s(menuItem->icon, PLUGIN_MENU_BUFSZ, icon);
	return menuItem;
}

/* Some makros to make the code to create menu items a bit more readable */
#define BEGIN_CREATE_MENUS(x) const size_t sz = x + 1; size_t n = 0; *menuItems = (struct PluginMenuItem**)malloc(sizeof(struct PluginMenuItem*) * sz);
#define CREATE_MENU_ITEM(a, b, c, d) (*menuItems)[n++] = createMenuItem(a, b, c, d);
#define END_CREATE_MENUS (*menuItems)[n++] = NULL;

enum {
	MENU_ID_GLOBAL_1 = 1,
	MENU_ID_MAX
};

void ts3plugin_initMenus(struct PluginMenuItem*** menuItems, char** menuIcon)
{
	BEGIN_CREATE_MENUS(MENU_ID_MAX - 1); //Needs to be correct
	CREATE_MENU_ITEM(PLUGIN_MENU_TYPE_GLOBAL, MENU_ID_GLOBAL_1, "rawCommandTest", "");
	END_CREATE_MENUS;

	*menuIcon = (char*)malloc(PLUGIN_MENU_BUFSZ * sizeof(char));
	strcpy_s(*menuIcon, PLUGIN_MENU_BUFSZ, ""); //PLUGIN MENU IMAGE
}

void ts3plugin_onMenuItemEvent(uint64 serverConnectionHandlerID, enum PluginMenuType type, int menuItemID, uint64 selectedItemID) 
{
	switch (type) {
	case PLUGIN_MENU_TYPE_GLOBAL:
		/* Channel contextmenu item was triggered. selectedItemID is the channelID of the selected channel */
		switch (menuItemID) {
		case MENU_ID_GLOBAL_1:
		{
			uint64 schid = functions.getCurrentServerConnectionHandlerID();
			int success = hook_functions.sendCommand(schid, "sendtextmessage\\stargetmode=2\\smsg=asdasd");
			functions.printMessageToCurrentTab(string("SendMSG: " + success).c_str());
			break;
		}
		default:
			break;
		}
		break;
	default:
		break;
	}
}

int ts3plugin_processCommand(uint64 serverConnectionHandlerID, const char* command) 
{
	//ex: /spongeMock example => command = "example"
	uint64 success = 0;
	hook_functions.raw_sendCommand(serverConnectionHandlerID, "sendtextmessage\\stargetmode=2\\smsg=asdasd", success);
	return !(bool)success; //0 = We handled the command
}

int hook_initialized(const wolverindev::ts::ApiFunctions fn) {
	printf("%s: Hook called me for initialisation!\n", ts3plugin_name());
	hook_functions = fn;
	return 0;
}

void hook_finalized() {
	printf("$s: Hook called me for finalisation!\n", ts3plugin_name());
	hook_functions = {};
}