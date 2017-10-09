#include <cppapi-c/project.h>
#include <cppapi-c/using_namespace/project.h>

CPPAPI_C_EXPORT int project_init(project* project)
{
	return cppapi_project_init(project);
}
CPPAPI_C_EXPORT int project_del(project* project)
{
	return cppapi_project_del(project);
}

CPPAPI_C_EXPORT int project_load(project project, const char* path)
{
	return cppapi_project_load(project, path);
}
CPPAPI_C_EXPORT int project_save(project project, const char* path)
{
	return cppapi_project_save(project, path);
}