#ifdef CPPAPI_MODULE
import cppapi.source;

import cppapi.code;
#else
#	include <cppapi/source.hh>

#	include <cppapi/code.hh>
#endif

#include <cppapi/details/source.inc.hh>

// source 클래스
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

	source_io source::get_io_object() const
	{
		return *this;
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

#define BIG_ENDIAN_REVERSE(name)										\
	if (is_big_endian)													\
	{																	\
		std::reverse(reinterpret_cast<std::uint8_t*>(&name),			\
			reinterpret_cast<std::uint8_t*>(&name) + sizeof(name));		\
	}

// source_io 클래스
namespace cppapi
{
	source_io::source_io(const source& source)
		: source_(source)
	{}
	source_io::source_io(const source_io& io_object)
		: source_(io_object.source_)
	{}

	void source_io::save(std::FILE* file, bool is_big_endian) const
	{
		std::fwrite(&source_.auto_remove_, sizeof(bool), 1, file);
		
		std::uint32_t name_length = source_.name_.length();
		BIG_ENDIAN_REVERSE(name_length);
		std::fwrite(&name_length, sizeof(std::uint32_t), 1, file);

		std::fwrite(source_.name_.c_str(), sizeof(std::uint8_t), name_length, file);

		std::uint32_t codes_count = source_.codes_.size();
		BIG_ENDIAN_REVERSE(codes_count);
		std::fwrite(&codes_count, sizeof(std::uint32_t), 1, file);

		for (const code* code : source_.codes_)
		{
			code->get_io_object().save(file, is_big_endian);
		}
	}
}