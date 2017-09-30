#ifdef CPPAPI_MODULE
import cppapi.source;
#else
#	include <cppapi/source.hh>
#endif

#include <cppapi/details/source.inc.hh>

namespace cppapi
{
	source::~source()
	{}

	source::source(project& project, const std::string& name)
		: source(project, name, true)
	{}
	source::source(project& project, const std::string& name, bool auto_remove)
		: project_(project), auto_remove_(auto_remove),
		name_(name)
	{}

	source* source::create(project& project, const std::string& name)
	{
		source* source = new cppapi::source(project, name);
		project.add_source_fast(source);

		return source;
	}
	source* source::create(project& project, const std::string& name, bool auto_remove)
	{
		source* source = new cppapi::source(project, name, auto_remove);
		project.add_source_fast(source);

		return source;
	}

	std::string source::name() const
	{
		return name_;
	}
	std::string source::name(const std::string& name)
	{
		return name_ = name;
	}
	bool source::auto_remove() const noexcept
	{
		return auto_remove_;
	}
	bool source::auto_remove(bool auto_remove) noexcept
	{
		return auto_remove_ = auto_remove;
	}
}