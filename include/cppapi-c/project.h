#ifndef CPPAPI_C_HEADER_PROJECT_H
#define CPPAPI_C_HEADER_PROJECT_H

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
	
	int cppapi_project_init(cppapi_project* project);
	int cppapi_project_del(cppapi_project* project);

#ifdef __cplusplus
}
#endif

#endif