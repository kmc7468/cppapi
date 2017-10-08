#ifdef CPPAPI_MODULE
module cppapi;

export import cppapi.builder;
export import cppapi.code;
export import cppapi.project;
export import cppapi.source;
#endif

#include <climits>
#include <cstddef>
#include <type_traits>

static_assert(CHAR_BIT == 8, "Only systems with 8 bits per byte are supported.");
static_assert(sizeof(char) == 1, "Only systems with char's a size of 1 byte are supported.");
static_assert(sizeof(std::size_t) >= 4, "Only compilers with std::size_t's a size of 4 bytes are supported.");
static_assert(std::is_unsigned<std::size_t>::value, "Only compilers with std::size_t is unsigned are supported.");