#pragma once

#ifdef WIN32
	#define PLUGINS_EXPORTDLL __declspec(dllexport)
#else
	#define PLUGINS_EXPORTDLL __attribute__ ((visibility("default")))
#endif

#ifdef __cplusplus
extern "C" {
#endif
	namespace wolverindev{
		namespace ts {
			struct ApiFunctions;
		}
	}

	PLUGINS_EXPORTDLL extern int hook_initialized(const wolverindev::ts::ApiFunctions);
	PLUGINS_EXPORTDLL extern void hook_finalized();
#ifdef __cplusplus
}
#endif