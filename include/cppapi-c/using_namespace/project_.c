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