#include <cppapi-c/project.h>
#include <cppapi-c/using_namespace/project.h>

int project_init(project* project)
{
	return cppapi_project_init(project);
}
int project_del(project* project)
{
	return cppapi_project_del(project);
}