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
		: source_(source), auto_remove_(true)
	{}
	code::code(source& source, bool auto_remove)
		: source_(source), auto_remove_(auto_remove)
	{}

	code* code::create(source* source)
	{
		code* result = new code(*source);
		source->add_code_fast(result);

		return result;
	}
	code* code::create(source* source, bool auto_remove)
	{
		code* result = new code(*source, auto_remove);
		source->add_code_fast(result);

		return result;
	}

	bool code::auto_remove() const noexcept
	{
		return auto_remove_;
	}
	bool code::auto_remove(bool auto_remove) noexcept
	{
		return auto_remove_ = auto_remove;
	}
}