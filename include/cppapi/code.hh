#if defined(CPPAPI) || !defined(CPPAPI_MODULE)
#	ifndef CPPAPI_HEADER_CODE_HH
#	define CPPAPI_HEADER_CODE_HH
#	include <cppapi/config.hh>
#	include <cppapi/details/code.inc.hh>

namespace cppapi
{
	CPPAPI_CLASS code
	{
		friend class code_saver;

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
		code_saver get_saver() const;

	public:
		bool auto_remove() const noexcept;
		bool auto_remove(bool auto_remove) noexcept;

	private:
		source& source_;
		bool auto_remove_;
	};

	CPPAPI_CLASS code_saver final
	{
		friend class project;
		friend class source_saver;

	public:
		code_saver(const code& code);
		code_saver(const code_saver& saver);
		code_saver(code_saver&& saver) noexcept = delete;
		~code_saver();

	public:
		source_saver& operator=(const source_saver& saver) = delete;
		source_saver& operator=(source_saver&& saver) noexcept = delete;
		bool operator==(const source_saver& saver) const = delete;
		bool operator!=(const source_saver& saver) const = delete;

	private:
		void operator()(std::FILE* file, bool is_big_endian) const;

	private:
		void save(std::FILE* file, bool is_big_endian) const;

	private:
		const code& code_;
	};
}

#	endif
#endif