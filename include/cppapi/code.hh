#if defined(CPPAPI) || !defined(CPPAPI_MODULE)
#	ifndef CPPAPI_HEADER_CODE_HH
#	define CPPAPI_HEADER_CODE_HH
#	include <cppapi/config.hh>
#	include <cppapi/details/code.inc.hh>

namespace cppapi
{
	CPPAPI_CLASS code
	{
	public:
		code(const code& code) = delete;
		code(code&& code) noexcept = delete;
		virtual ~code();

	private:
		code(source& source);
		code(source& source, bool auto_remove);

	public:
		static code* create(source* source);
		static code* create(source* source, bool auto_remove);

	public:
		bool auto_remove() const noexcept;
		bool auto_remove(bool auto_remove) noexcept;

	private:
		source& source_;
		bool auto_remove_;
	};
}

#	endif
#endif