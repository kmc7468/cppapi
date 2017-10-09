#ifndef CPPAPI_C_HEADER_USING_NAMESPACE_PROJECT_H
#define CPPAPI_C_HEADER_USING_NAMESPACE_PROJECT_H

#if defined(CPPAPI_C_HEADER_PROJECT_H) && !defined(CPPAPI_C_MACRO_PROJECT_USINGED)
#	define CPPAPI_C_MACRO_PROJECT_USINGED

typedef cppapi_project project;

#	ifdef __cplusplus
extern "C"
{
#	endif

	CPPAPI_C_EXPORT int project_init(project* project);
	CPPAPI_C_EXPORT int project_del(project* project);

#	ifdef __cplusplus
}
#	endif
#endif

#endif