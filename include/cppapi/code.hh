#if defined(CPPAPI) || !defined(CPPAPI_MODULE)
#	ifndef CPPAPI_HEADER_CODE_HH
#	define CPPAPI_HEADER_CODE_HH
#	include <cppapi/config.hh>
#	include <cppapi/details/code.inc.hh>

namespace cppapi
{
	CPPAPI_CLASS code final
	{
	public:
		code(const code& code) = delete;
		code(code&& code) noexcept = delete;
		~code();

	private:
		code(source& source);

	private:
		source& source_;
	};
}

#	endif
#endif