#include <cppapi-c/project.h>

#include <cstddef>
#include <new>

extern "C"
{
	int cppapi_project_init(cppapi_project* project)
	{
		if (project == NULL) return 1;

		*project = new(std::nothrow) cppapi::project();

		if (*project == NULL) return -1;

		return 0;
	}
	int cppapi_project_del(cppapi_project* project)
	{
		if (project == NULL) return 1;

		delete *project;
		*project = NULL;

		return 0;
	}
}