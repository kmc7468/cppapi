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
	private:
		class gc_ final
		{
		public:
			enum class value_type
			{
				source
			};

		public:
			gc_();
			gc_(const gc_& gc) = delete;
			gc_(gc_&& gc) noexcept = delete;
			~gc_();

		public:
			gc_& operator=(const gc_& gc) = delete;
			gc_& operator=(gc_&& gc) noexcept = delete;
			bool operator==(const gc_& gc) const = delete;
			bool operator!=(const gc_& gc) const = delete;
			
		private:
			std::vector<std::pair<value_type, void*>> allocated_memories_;
		};

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
		void remove_source(source* source);
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