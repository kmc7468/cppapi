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

	CPPAPI_C_EXPORT int cppapi_project_load(cppapi_project project, const char* path)
	{
		if (project == NULL) return 1;
		if (path == NULL) return 2;

		try
		{
			project->load(path);

			return 0;
		}
		catch (...)
		{
			return -1;
		}
	}
	CPPAPI_C_EXPORT int cppapi_project_save(cppapi_project project, const char* path)
	{
		if (project == NULL) return 1;
		if (path == NULL) return 2;

		try
		{
			project->save(path);

			return 0;
		}
		catch (...)
		{
			return -1;
		}
	}
}