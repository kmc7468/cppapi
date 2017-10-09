#include <cppapi-c/error.h>

#include <cstddef>
#include <map>
#include <thread>

extern "C"
{
#ifdef CPPAPI_C_SINGLE_THREAD
	static const char* cppapi_last_error_function;
	static const char* cppapi_last_error_message;
#else
	static std::map<std::thread::id, const char*> cppapi_last_error_function;
	static std::map<std::thread::id, const char*> cppapi_last_error_message;
#endif

	cppapi_error cppapi_get_last_error()
	{
#ifdef CPPAPI_C_SINGLE_THREAD
		return { cppapi_last_error_function, cppapi_last_error_message };
#else
		return
		{ cppapi_last_error_function[std::this_thread::get_id()],
		  cppapi_last_error_message[std::this_thread::get_id()] };
#endif
	}
	int cppapi_set_last_error(cppapi_error error)
	{
#ifdef CPPAPI_C_SINGLE_THREAD
		cppapi_last_error_function = error.function;
		cppapi_last_error_message = error.message;
#else
		cppapi_last_error_function[std::this_thread::get_id()] = error.function;
		cppapi_last_error_message[std::this_thread::get_id()] = error.message;
#endif

		return 0;
	}
}