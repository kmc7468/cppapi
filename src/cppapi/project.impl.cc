#ifdef CPPAPI_MODULE
import cppapi.project;

import cppapi.code;
import cppapi.source;
#else
#	include <cppapi/project.hh>

#	include <cppapi/code.hh>
#	include <cppapi/source.hh>

#	include <algorithm>
#	include <cstdio>
#	include <cstdlib>
#	include <new>
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

#define BIG_ENDIAN_REVERSE(name)										\
	if (is_big_endian)													\
	{																	\
		std::reverse(reinterpret_cast<std::uint8_t*>(&name),			\
			reinterpret_cast<std::uint8_t*>(&name) + sizeof(name));		\
	}

	void project::load(const std::string& path)
	{
		std::FILE* file = std::fopen(path.c_str(), "rb");

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

		std::uint8_t* buffer = reinterpret_cast<std::uint8_t*>(std::calloc(8, sizeof(std::uint8_t)));

		if (buffer == nullptr)
			throw std::bad_alloc();

		struct buffer_raii
		{
			buffer_raii(std::uint8_t** buffer)
				: buffer(buffer)
			{}
			~buffer_raii()
			{
				std::free(*buffer);
			}
			
			std::uint8_t** buffer;
		} buffer_raii_inst(&buffer);

		std::fread(buffer, sizeof(std::uint8_t), 8, file);

		if (!std::equal(buffer, buffer + 8, project::magic_number_, project::magic_number_ + 8))
			throw std::invalid_argument("The loaded file is not a normal cppapi project file.");

		std::fread(buffer, sizeof(std::uint32_t), 1, file);

		std::uint32_t loaded_version = *reinterpret_cast<std::uint32_t*>(buffer);
		BIG_ENDIAN_REVERSE(loaded_version);

		switch (loaded_version)
		{
		case 0:
			load_v0_(file, &buffer, is_big_endian);
			break;

		default:
			throw std::invalid_argument("Does not support the loaded cppapi project file's version.");
		}
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
		BIG_ENDIAN_REVERSE(source_count);
		std::fwrite(&source_count, sizeof(std::uint32_t), 1, file);

		for (const source* src : sources_)
		{
			src->get_io_object().save(file, is_big_endian);
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
	void project::erase_source(source* source)
	{
		std::vector<cppapi::source*>::iterator source_iter;

		if (source_iter = std::find(sources_.begin(), sources_.end(), source); source_iter == sources_.end()) return;

		sources_.erase(source_iter);
	}

	void project::load_v0_(std::FILE* file, std::uint8_t** buffer, bool is_big_endian)
	{
		std::fread(*buffer, sizeof(std::uint32_t), 1, file);

		std::uint32_t source_count = *reinterpret_cast<std::uint32_t*>(*buffer);
		BIG_ENDIAN_REVERSE(source_count);

		for (std::uint32_t i = 0; i < source_count; ++i)
		{
			sources_.push_back(source_io::load_v0(file, is_big_endian, buffer, *this));
		}
	}

	const std::vector<source*>& project::sources() const noexcept
	{
		return sources_;
	}

	const std::uint8_t project::magic_number_[]
		= { 0xC8, 'F', 'U', 'C', 'K', 'C', 'P', 'P' };
	const std::uint32_t project::version_ = 0;
	const std::size_t project::length_max_ = 4294967295;
}