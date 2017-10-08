#ifdef CPPAPI_MODULE
import cppapi.source;

import cppapi.code;
#else
#	include <cppapi/source.hh>

#	include <cppapi/code.hh>
#endif

#include <cppapi/details/source.inc.hh>

namespace cppapi
{
	source::~source()
	{
		for (code* code : codes_)
		{
			if (code->auto_remove())
			{
				delete code;
			}
		}
	}

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

	void source::add_code(code* code)
	{
		if (std::find(codes_.begin(), codes_.end(), code) != codes_.end()) return;

		codes_.push_back(code);
	}
	void source::add_code_fast(code* code)
	{
		codes_.push_back(code);
	}
	void source::erase_code(code* code)
	{
		std::vector<cppapi::code*>::iterator code_iter;

		if (code_iter = std::find(codes_.begin(), codes_.end(), code); code_iter == codes_.end()) return;

		codes_.erase(code_iter);
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

	const std::vector<code*>& source::codes() const noexcept
	{
		return codes_;
	}
}