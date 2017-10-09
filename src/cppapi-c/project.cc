#include <cppapi-c/project.h>

#include <cstddef>
#include <new>

extern "C"
{
	CPPAPI_C_EXPORT int cppapi_project_init(cppapi_project* project)
	{
		if (project == NULL)
			CPPAPI_C_ERROR("The argument 'project' can't be a NULL pointer.", 1);

		*project = new(std::nothrow) cppapi::project();

		if (*project == NULL)
			CPPAPI_C_ERROR("Failed to dynamic allocate.", -1);

		return 0;
	}
	CPPAPI_C_EXPORT int cppapi_project_del(cppapi_project* project)
	{
		if (project == NULL)
			CPPAPI_C_ERROR("The argument 'project' can't be a NULL pointer.", 1);

		delete *project;
		*project = NULL;

		return 0;
	}

	CPPAPI_C_EXPORT int cppapi_project_load(cppapi_project project, const char* path)
	{
		if (project == NULL)
			CPPAPI_C_ERROR("The argument 'project' can't be a NULL pointer.", 1);
		if (path == NULL)
			CPPAPI_C_ERROR("The argument 'path' can't be a NULL pointer.", 1);

		try
		{
			project->load(path);

			return 0;
		}
		catch (...)
		{
			CPPAPI_C_ERROR("An unknown error has occurred.", -1);
		}
	}
	CPPAPI_C_EXPORT int cppapi_project_save(cppapi_project project, const char* path)
	{
		if (project == NULL)
			CPPAPI_C_ERROR("The argument 'project' can't be a NULL pointer.", 1);
		if (path == NULL)
			CPPAPI_C_ERROR("The argument 'path' can't be a NULL pointer.", 1);

		try
		{
			project->save(path);

			return 0;
		}
		catch (...)
		{
			CPPAPI_C_ERROR("An unknown error has occurred.", -1);
		}
	}
}