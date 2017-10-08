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
		void load_v0_(std::FILE* file, std::uint8_t** buffer, bool is_big_endian);

	private:
		static const std::uint8_t magic_number_[8];
		static const std::uint32_t version_;
		static const std::size_t length_max_;

	private:
		std::vector<source*> sources_;
	};
}

#	endif
#endif