#if defined(CPPAPI) || !defined(CPPAPI_MODULE)
#	ifndef CPPAPI_HEADER_PROJECT_HH
#	define CPPAPI_HEADER_PROJECT_HH
#	include <cppapi/config.hh>
#	include <cppapi/details/project.inc.hh>

namespace cppapi
{
	class source;

	CPPAPI_CLASS project final
	{
	public:
		project();
		project(const project& project) = delete;
		project(project&& project) noexcept = delete;
		~project();

	public:
		void load(const std::string& path);
		void save(const std::string& path) const;
		void add_source(source* source);
		void add_source_fast(source* source);
		void erase_source(source* source);

	private:
		static const std::uint8_t magic_number_[8];
		static const std::uint64_t version_;

	private:
		std::vector<source*> sources_;
	};
}

#	endif
#endif