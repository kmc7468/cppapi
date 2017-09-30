#ifdef CPPAPI_MODULE
import cppapi.project;
#else
#	include <cppapi/project.hh>

#	include <fstream>
#	include <ios>
#	include <stdexcept>
#	include <vector>
#endif

#include <cppapi/details/project.inc.hh>

namespace cppapi
{
	void project::load(const std::string& path)
	{
		std::basic_ifstream<std::uint8_t> file(path, std::ios::binary);

		if (!file.is_open())
		{
			throw std::ios_base::failure("������ ���� ���߽��ϴ�.");
		}

		std::vector<std::uint8_t> buffer;
		
		buffer.resize(8);
		file.read(&buffer[0], 8);

		if (!std::equal(buffer.begin(), buffer.end(), magic_number_, magic_number_ + 8))
		{
			file.close();
			throw std::invalid_argument("cppapi ������Ʈ ������ �ƴմϴ�.");
		}

		file.close();
	}
	void project::save(const std::string& path) const
	{
		std::basic_ofstream<std::uint8_t> file(path, std::ios::binary);
		
		if (!file.is_open())
		{
			throw std::ios_base::failure("������ ���� ���߽��ϴ�.");
		}

		file << magic_number_;

		file.close();
	}
}