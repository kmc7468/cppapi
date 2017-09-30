#ifndef CPPAPI_HEADER_CONFIG_HH
#define CPPAPI_HEADER_CONFIG_HH

#if defined(CPPAPI_MODULE) && defined(CPPAPI_DYNAMIC) && defined(_MSC_VER)
#	error Compiling module in MSVC, you must use static linking.
#endif

#if defined(CPPAPI) && defined(CPPAPI_MODULE)
#	define CPPAPI_EXPORT export
#	define CPPAPI_DLLEXPORT
#elif defined(CPPAPI) && defined(CPPAPI_DYNAMIC) && defined(_MSC_VER)
#	define CPPAPI_EXPORT
#	define CPPAPI_DLLEXPORT __declspec(dllexport)
#elif !defined(CPPAPI) && defined(CPPAPI_DYNAMIC) && defined(_MSC_VER)
#	define CPPAPI_EXPORT
#	define CPPAPI_DLLEXPORT __declspec(dllimport)
#else
#	define CPPAPI_EXPORT
#	define CPPAPI_DLLEXPORT
#endif

#define CPPAPI_CLASS						\
CPPAPI_EXPORT class CPPAPI_DLLEXPORT

#define CPPAPI_STRUCT						\
CPPAPI_EXPORT struct CPPAPI_DLLEXPORT

#endif