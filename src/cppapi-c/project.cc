#include <cppapi-c/project.h>

#include <cstddef>
#include <new>

extern "C"
{
	CPPAPI_C_EXPORT int cppapi_project_init(cppapi_project* project)
	{
		if (project == NULL) return 1;

		*project = new(std::nothrow) cppapi::project();

		if (*project == NULL) return -1;

		return 0;
	}
	CPPAPI_C_EXPORT int cppapi_project_del(cppapi_project* project)
	{
		if (project == NULL) return 1;

		delete *project;
		*project = NULL;

		return 0;
	}
}