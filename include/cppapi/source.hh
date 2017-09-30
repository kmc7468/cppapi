#if defined(CPPAPI) || !defined(CPPAPI_MODULE)
#	ifndef CPPAPI_HEADER_SOURCE_HH
#	define CPPAPI_HEADER_SOURCE_HH
#	include <cppapi/config.hh>
#	include <cppapi/details/source.inc.hh>

namespace cppapi
{
	CPPAPI_CLASS source final
	{
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
		static source* create_source(project& project, const std::string& name);
		static source* create_source(project& project, const std::string& name, bool auto_remove);

	public:
		std::string name() const;
		std::string name(const std::string& name);
		bool auto_remove() const noexcept;

	private:
		project& project_;
		bool auto_remove_;

		std::string name_;
	};
}

#	endif
#endif