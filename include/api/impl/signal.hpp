#pragma once


#ifdef _WINDOWS
	#include <Windows.h>
	#include <Psapi.h>
#else
    #include <deque>
    #include <link.h>
#endif

#define EVENT_PLUGIN_ENABLED "ts3plugin_plugin_enabled"
inline void trigger_plugin_loaded() {
	typedef void(*EventPluginEnabled)();
	
#ifdef WIN32
	HMODULE hMods[1024];
	DWORD cbNeeded;

	if(EnumProcessModulesEx(GetCurrentProcess(), hMods, sizeof(hMods), &cbNeeded, LIST_MODULES_ALL)) {
		for (size_t index = 0; index < (cbNeeded / sizeof(HMODULE)); index++) {
			auto callback = (EventPluginEnabled) GetProcAddress(hMods[index], EVENT_PLUGIN_ENABLED);
			if(callback) callback();
		}
	}
#else
	std::deque<std::string> modules;
	auto callback = [](struct dl_phdr_info *info, size_t size, void *ptr) {
		auto list = (std::deque<std::string>*) ptr;
		list->push_back(info->dlpi_name);
		return 0;
	};
	dl_iterate_phdr(callback, &modules);

	for(const auto& module : modules) {
		auto handle = dlopen(module.c_str(), RTLD_LAZY);
		if(!handle) continue;
		auto call = (EventPluginEnabled)  dlsym(handle, EVENT_PLUGIN_ENABLED);
		if(call) call();
	}
#endif
}