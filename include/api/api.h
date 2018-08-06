#pragma once

#include <tuple>
#include <string>

#ifndef WIN32
	#define __in
	#define __out
	#include <cstring>
    #include <stdlib.h>
#endif

namespace wolverindev {
    namespace ts {
		struct Hook;
		struct HookSpecifications;
		
        typedef uint64_t SCHId;
        enum ErrorCode : int {
            ERROR_OK = 0,
            ERROR_HOOK_ALREADY_REGISTERED = -1,
            ERROR_HOOK_NOT_FOUND = -2,
			ERROR_INTERNAL = -3,
			ERROR_COULD_NOT_SEND_COMMAN = -4,
        };

		struct ApiFunctions {
			uint64_t(*raw_getVersion)() = nullptr;
			
			ErrorCode(*registerHook)(Hook*) = nullptr;
			bool(*hookRegistered)(Hook*) = nullptr;
			ErrorCode(*unregisterHook)(Hook*) = nullptr;

			/**
			 * @parm The target server id
			 * @parm The command as escaped string
			 * @return 1 on success
			 */
			ErrorCode (*raw_sendCommand)(SCHId, const char*, size_t) = nullptr;
			
			bool(*thread_save)() = nullptr;
			bool(*hook_availible)() = nullptr;

			HookSpecifications(*hook_specifications)() = nullptr;


			/* ------ helpers ------ */
			inline std::tuple<int, int, int> getVersion() {
				auto version = this->raw_getVersion();
				return std::make_tuple((int) (int16_t) (version >> 32), (int) (int16_t) (version >> 16), (int) (int16_t) (version >> 0));
			};
			ErrorCode sendCommand(SCHId schId, const std::string& command) { return this->raw_sendCommand(schId, command.data(), command.length()); }
		};
        
		class CommandPacket {
			private:
				char* buffer = nullptr;
				size_t _length = 0;
				size_t allocated = 0;
			public:
				std::string data() { return std::string(buffer, _length); }
				void data(const std::string& data) {
					if(data.length() > allocated) {
						if(buffer) free(buffer);
						allocated = data.length();
						buffer = (char*) malloc(allocated);
					}
					memcpy(buffer, data.data(), data.length());
					_length = data.length();
				}
				
				size_t length() { return this->_length; }
				
				const char* ptr() { return this->buffer; }
		};

		struct HookSpecifications {
			bool packet_out            = false;
			bool packet_out_expendable = false;
			bool packet_out_cancelable = false;

			bool packet_in             = false;
			bool packet_in_expendable  = false;
			bool packet_in_cancelable  = false;
		};
		
        struct Hook {
            /**
             * @note this field could be null
             * @details A empty methode is treat as true
             */
            bool (*activated)()                                                                       = nullptr;

            /**
             * @note this field could be null
             * @details Returns the weight of the hook (if null its treat as zero)
             */
            int (*weight)()                                                                           = nullptr;

            /**
             * @note this field could be null
             * @parm The server connection handler id (could be zero for unknown)
             * @parm The command as string (if edited the new command should be smaller or equal then the old one!)
             */
            void (*on_packet_in)(__in SCHId, __in CommandPacket*, __in __out bool &canceled)          = nullptr;

            /**
             * @note this field could be null
             * @parm The server connection handler id (could be zero for unknown)
             * @parm The command as string (if edited the new command should be smaller or equal then the old one!)
             */
            void (*on_packet_out)(__in SCHId, __in CommandPacket*, __in __out bool &canceled)         = nullptr;
        };
    }
}

#include "impl/signal.hpp"