#ifndef CPPAPI_C_HEADER_PROJECT_H
#define CPPAPI_C_HEADER_PROJECT_H
#include <cppapi-c/config.h>

#include <stddef.h>

#ifdef __cplusplus
#	include <cppapi/project.hh>

typedef cppapi::project* cppapi_project;
#else
typedef struct project* cppapi_project;
#endif

#ifdef __cplusplus
extern "C"
{
#endif
	
	CPPAPI_C_EXPORT int cppapi_project_init(cppapi_project* project);
	CPPAPI_C_EXPORT int cppapi_project_del(cppapi_project* project);

	CPPAPI_C_EXPORT int cppapi_project_load(cppapi_project project, const char* path);
	CPPAPI_C_EXPORT int cppapi_project_save(cppapi_project project, const char* path);

#ifdef __cplusplus
}
#endif

#endif