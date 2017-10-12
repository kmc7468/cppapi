#include <cppapi-c/source.h>

#include <cstddef>
#include <cstring>

extern "C"
{
	CPPAPI_C_EXPORT int cppapi_source_create(cppapi_source* source, cppapi_project project, const char* name,
		int auto_remove)
	{
		if (source == NULL)
			CPPAPI_C_ERROR("The argument 'source' can't be a NULL pointer.", 1);
		if (project == NULL)
			CPPAPI_C_ERROR("The argument 'project' can't be a NULL pointer.", 1);
		if (project == NULL)
			CPPAPI_C_ERROR("The argument 'name' can't be a NULL pointer.", 1);

		cppapi_source result = cppapi::source::create(*project, name, auto_remove);
		*source = result;

		return 0;
	}

	CPPAPI_C_EXPORT int cppapi_source_get_name(cppapi_source source, char* name, size_t length)
	{
		if (source == NULL)
			CPPAPI_C_ERROR("The argument 'source' can't be a NULL pointer.", 1);
		if (name == NULL)
			CPPAPI_C_ERROR("The argument 'name' can't be a NULL pointer.", 1);
		if (length == 0)
			CPPAPI_C_ERROR("The argument 'length' must have a value greater than or equal to 1.", 2);
		
		if (length > source->name().size())
		{
			std::strncpy(name, source->name().c_str(), source->name().length());
		}
		else
		{
			std::strncpy(name, source->name().c_str(), length);
		}

		return 0;
	}
	CPPAPI_C_EXPORT int cppapi_source_get_name_address(cppapi_source source, const char** name)
	{
		if (source == NULL)
			CPPAPI_C_ERROR("The argument 'source' can't be a NULL pointer.", 1);
		if (name == NULL)
			CPPAPI_C_ERROR("The argument 'name' can't be a NULL pointer.", 1);

		*name = source->name().c_str();

		return 0;
	}
	CPPAPI_C_EXPORT int cppapi_source_get_name_length(cppapi_source source, size_t* length)
	{
		if (source == NULL)
			CPPAPI_C_ERROR("The argument 'source' can't be a NULL pointer.", 1);
		if (length == NULL)
			CPPAPI_C_ERROR("The argument 'length' can't be a NULL pointer.", 1);

		*length = source->name().length();

		return 0;
	}
	CPPAPI_C_EXPORT int cppapi_source_set_name(cppapi_source source, const char* name)
	{
		if (source == NULL)
			CPPAPI_C_ERROR("The argument 'source' can't be a NULL pointer.", 1);

		source->name().resize(std::strlen(name));
		std::strcpy(const_cast<char*>(source->name().c_str()), name);

		return 0;
	}
}