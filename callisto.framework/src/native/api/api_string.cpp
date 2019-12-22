// parent heade
#include <callisto/framework/native/api/api_string.hpp>
// memory
#include <memory>
#include <cstring>

using namespace callisto::framework;

std::string get_string(API_String str)
{
	if (str.coding_type != CodingType_ASCII) throw std::runtime_error("coding != ASCII");
	std::string s;
	s.resize(str.size);
	auto strPtr = (void*)s.data();
	std::memcpy(strPtr, str.data, str.size);

	return std::move(s);
}

std::string_view getStringView(API_String str)
{
	if (str.coding_type != CodingType_ASCII) throw std::runtime_error("coding != ASCII");
	return std::string_view((char*)str.data, str.size);
}