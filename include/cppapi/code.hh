#if defined(CPPAPI) || !defined(CPPAPI_MODULE)
#	ifndef CPPAPI_HEADER_CODE_HH
#	define CPPAPI_HEADER_CODE_HH
#	include <cppapi/config.hh>
#	include <cppapi/details/code.inc.hh>

namespace cppapi
{
	CPPAPI_CLASS code
	{
		friend class code_io;

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
		code_io get_io_object() const;

	public:
		bool auto_remove() const noexcept;
		bool auto_remove(bool auto_remove) noexcept;

	private:
		source& source_;
		bool auto_remove_;
	};

	CPPAPI_CLASS code_io final
	{
		friend class project;
		friend class source_io;

	public:
		code_io(const code& code);
		code_io(const code_io& io_object);
		code_io(code_io&& io_object) noexcept = delete;
		~code_io();

	public:
		code_io& operator=(const code_io& io_object) = delete;
		code_io& operator=(code_io&& io_object) noexcept = delete;
		bool operator==(const code_io& io_object) const = delete;
		bool operator!=(const code_io& io_object) const = delete;

	private:
		void save(std::FILE* file, bool is_big_endian) const;

	private:
		const code& code_;
	};
}

#	endif
#endif