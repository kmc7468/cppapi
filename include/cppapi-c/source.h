#ifndef CPPAPI_C_HEADER_SOURCE_H
#define CPPAPI_C_HEADER_SOURCE_H
#include <cppapi-c/config.h>

#include <cppapi-c/project.h>

#ifdef __cplusplus
#	include <cppapi/source.hh>

typedef cppapi::source* cppapi_source;
#else
typedef struct cppapi_source* cppapi_source;
#endif

#ifdef __cplusplus
extern "C"
{
#endif

	CPPAPI_C_EXPORT int cppapi_source_create(cppapi_source* source, cppapi_project project, const char* name,
		int auto_remove = 1);

	CPPAPI_C_EXPORT int cppapi_source_get_name(cppapi_source source, char* name, size_t length);
	CPPAPI_C_EXPORT int cppapi_source_get_name_address(cppapi_source source, const char** name);
	CPPAPI_C_EXPORT int cppapi_source_get_name_length(cppapi_source source, size_t* length);
	CPPAPI_C_EXPORT int cppapi_source_set_name(cppapi_source source, const char* name);

#ifdef __cplusplus
}
#endif

#endif