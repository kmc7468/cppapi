#ifdef CPPAPI_MODULE
import cppapi.code;
#else
#	include <cppapi/code.hh>
#endif

#include <cppapi/details/code.inc.hh>

// code 클래스
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

	code_io code::get_io_object() const
	{
		return *this;
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

#define BIG_ENDIAN_REVERSE(name)										\
	if (is_big_endian)													\
	{																	\
		std::reverse(reinterpret_cast<std::uint8_t*>(&name),			\
			reinterpret_cast<std::uint8_t*>(&name) + sizeof(name));		\
	}

// code_io 클래스
namespace cppapi
{
	code_io::code_io(const code& code)
		: code_(code)
	{}
	code_io::code_io(const code_io& io_object)
		: code_(io_object.code_)
	{}

	void code_io::save(std::FILE* file, bool is_big_endian) const
	{
		std::fwrite(&code_.auto_remove_, sizeof(bool), 1, file);
	}
}