#if defined(CPPAPI) || !defined(CPPAPI_MODULE)
#	ifndef CPPAPI_HEADER_SOURCE_HH
#	define CPPAPI_HEADER_SOURCE_HH
#	include <cppapi/config.hh>
#	include <cppapi/details/source.inc.hh>

namespace cppapi
{
	class code;

	CPPAPI_CLASS source final
	{
		friend class source_io;

	public:
		source(const source& source) = delete;
		source(source&& source) noexcept = delete;
		~source();

	private:
		source(project& project, const std::string& name);
		source(project& project, const std::string& name, bool auto_remove);

	public:
		source& operator=(const source& source) = delete;
		source& operator=(source&& source) noexcept = delete;
		bool operator==(const source& source) const = delete;
		bool operator!=(const source& source) const = delete;

	public:
		static source* create(project& project, const std::string& name);
		static source* create(project& project, const std::string& name, bool auto_remove);

	public:
		void add_code(code* code);
		void add_code_fast(code* code);
		void erase_code(code* code);

		source_io get_io_object() const;

	public:
		std::string name() const;
		std::string name(const std::string& name);
		bool auto_remove() const noexcept;
		bool auto_remove(bool auto_remove) noexcept;

		const std::vector<code*>& codes() const noexcept;

	private:
		project& project_;
		bool auto_remove_;

		std::string name_;
		std::vector<code*> codes_;
	};

	CPPAPI_CLASS source_io final
	{
		friend class project;

	public:
		source_io(const source& source);
		source_io(const source_io& io_object);
		source_io(source_io&& io_object) noexcept = delete;
		~source_io();

	public:
		source_io& operator=(const source_io& io_object) = delete;
		source_io& operator=(source_io&& io_object) noexcept = delete;
		bool operator==(const source_io& io_object) const = delete;
		bool operator!=(const source_io& io_object) const = delete;

	private:
		void save(std::FILE* file, bool is_big_endian) const;

	private:
		const source& source_;
	};
}

#	endif
#endif