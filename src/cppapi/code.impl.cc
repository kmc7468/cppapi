#ifdef CPPAPI_MODULE
import cppapi.code;
#else
#	include <cppapi/code.hh>
#endif

#include <cppapi/details/code.inc.hh>

namespace cppapi
{
	code::~code()
	{}

	code::code(source& source)
		: source_(source)
	{}
}