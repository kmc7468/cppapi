#ifdef CPPAPI_MODULE
import cppapi.builder;
#else
#	include <cppapi/builder.hh>
#endif

#include <cppapi/details/builder.inc.hh>

namespace cppapi
{
	builder::builder(project& project)
		: project_(project)
	{}
	builder::~builder()
	{}
}