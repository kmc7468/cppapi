#if defined(CPPAPI) || !defined(CPPAPI_MODULE)
#	ifndef CPPAPI_HEADER_PROJECT_HH
#	define CPPAPI_HEADER_PROJECT_HH
#	include <cppapi/config.hh>
#	include <cppapi/details/project.inc.hh>

namespace cppapi
{
	CPPAPI_CLASS project final
	{
	public:
		void load(const std::string& path);
		void save(const std::string& path) const;

	private:
		static const std::uint8_t magic_number_[8];
		static const std::uint64_t version_;
	};
}

#	endif
#endif