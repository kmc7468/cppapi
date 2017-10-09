#ifndef CPPAPI_C_HEADER_CONFIG_H
#define CPPAPI_C_HEADER_CONFIG_H

#if defined(CPPAPI_C_DYNAMIC) && defined(_MSC_VER)
#	ifdef CPPAPI_C
#		define CPPAPI_C_EXPORT __declspec(dllexport)
#	else
#		define CPPAPI_C_EXPORT __declspec(dllimport)
#	endif
#else
#	define CPPAPI_C_EXPORT
#endif

#endif