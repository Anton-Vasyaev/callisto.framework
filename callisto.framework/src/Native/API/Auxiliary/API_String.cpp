// parent heade
#include <Callisto/Framework/Native/API/API_String.hpp>
// memory
#include <memory>
#include <cstring>

namespace Callisto::Framework
{
	std::string getString(API_String str)
	{
		if (str.codingType != CodingType_ASCII) throw std::runtime_error("coding != ASCII");
		std::string s;
		s.resize(str.size);
		auto strPtr = (void*)s.data();
		std::memcpy(strPtr, str.data, str.size);

		return std::move(s);
	}

	std::string_view getStringView(API_String str)
	{
		if (str.codingType != CodingType_ASCII) throw std::runtime_error("coding != ASCII");
		return std::string_view((char*)str.data, str.size);
	}
}