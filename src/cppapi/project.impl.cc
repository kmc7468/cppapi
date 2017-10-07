#ifdef CPPAPI_MODULE
import cppapi.project;

import cppapi.source;
#else
#	include <cppapi/project.hh>

#	include <cppapi/source.hh>

#	include <algorithm>
#	include <cstdio>
#	include <stdexcept>
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
		std::FILE* file = std::fopen(path.c_str(), "wb");

		if (file == nullptr)
			throw std::invalid_argument("Failed to open file.");

		struct file_raii
		{
			file_raii(std::FILE* file)
				: file(file)
			{}
			~file_raii()
			{
				std::fclose(file);
			}

			std::FILE* file;
		} file_raii_inst(file);

		bool is_big_endian = false;
		
		{
			std::uint16_t temp = 1;

			if (*reinterpret_cast<std::uint8_t*>(&temp) == 0)
			{
				is_big_endian = true;
			}
		}

		std::fwrite(project::magic_number_, sizeof(std::uint8_t), 8, file);
		if (is_big_endian)
		{
			std::int32_t version_reversed = project::version_;
			std::reverse(reinterpret_cast<std::uint8_t*>(&version_reversed),
				reinterpret_cast<std::uint8_t*>(&version_reversed) + 4);
		}
		else
		{
			std::fwrite(&project::version_, sizeof(std::uint32_t), 1, file);
		}

		std::uint32_t source_count = sources_.size();
		if (is_big_endian)
		{
			std::reverse(reinterpret_cast<std::uint8_t*>(&source_count),
				reinterpret_cast<std::uint8_t*>(&source_count) + 4);
		}
		std::fwrite(&source_count, sizeof(std::uint32_t), 1, file);

		for (const source* src : sources_)
		{
			bool src_auto_remove = src->auto_remove();
			std::fwrite(&src_auto_remove, sizeof(bool), 1, file);

			std::string src_name = src->name();
			std::fwrite(src_name.c_str(), src_name.length(), 1, file);
		}
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
	void project::remove_source(source* source)
	{
		std::vector<cppapi::source*>::iterator source_iter;

		if (source_iter = std::find(sources_.begin(), sources_.end(), source); source_iter == sources_.end()) return;

		sources_.erase(source_iter);
	}
	void project::erase_source(source* source)
	{
		std::vector<cppapi::source*>::iterator source_iter;

		if (source_iter = std::find(sources_.begin(), sources_.end(), source); source_iter == sources_.end()) return;

		if ((*source_iter)->auto_remove())
		{
			delete *source_iter;
		}

		sources_.erase(source_iter);
	}

	const std::uint8_t project::magic_number_[]
		= { 0xC8, 'F', 'U', 'C', 'K', 'C', 'P', 'P' };
	const std::uint32_t project::version_ = 0;
	const std::size_t project::length_max_ = 4294967295;
}