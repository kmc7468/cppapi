#ifdef CPPAPI_MODULE
import cppapi.project;

import cppapi.source;
#else
#	include <cppapi/project.hh>

#	include <cppapi/source.hh>

#	include <algorithm>
#	include <vector>
#endif

#include <cppapi/details/project.inc.hh>

namespace cppapi
{
	project::project()
	{}
	project::~project()
	{
		for (source* src : sources_)
		{
			if (src->auto_remove())
			{
				delete src;
			}
		}
	}

	void project::load(const std::string& path)
	{
		// TODO
	}
	void project::save(const std::string& path) const
	{
		// TODO
	}
	void project::add_source(source* source)
	{
		if (std::find(sources_.begin(), sources_.end(), source) != sources_.end()) return;

		sources_.push_back(source);
	}
	void project::add_source_fast(source* source)
	{
		sources_.push_back(source);
	}
	void project::erase_source(source* source)
	{
		std::vector<cppapi::source*>::iterator source_iter;

		if (source_iter = std::find(sources_.begin(), sources_.end(), source); source_iter == sources_.end()) return;

		sources_.erase(source_iter);
	}

	const std::uint8_t project::magic_number_[]
		= { 0xC8, 'F', 'U', 'C', 'K', 'C', 'P', 'P' };
	const std::uint64_t project::version_ = 0;
}