#if defined(CPPAPI) || !defined(CPPAPI_MODULE)
#	ifndef CPPAPI_HEADER_BUILDER_HH
#	define CPPAPI_HEADER_BUILDER_HH
#	include <cppapi/config.hh>
#	include <cppapi/details/builder.inc.hh>

namespace cppapi
{
	CPPAPI_CLASS builder final
	{
	public:
		builder(project& project);
		builder(const builder& builder) = delete;
		builder(builder&& builder) noexcept = delete;
		~builder();

	public:
		builder& operator=(const builder& builder) = delete;
		builder& operator=(builder&& builder) noexcept = delete;
		bool operator==(const builder& builder) const = delete;
		bool operator!=(const builder& builder) const = delete;

	private:
		project& project_;
	};
}

#	endif
#endif