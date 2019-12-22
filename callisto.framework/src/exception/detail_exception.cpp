// parent header
#include <callisto/framework/exception/detail_exception.hpp>
// std
#include <sstream>
// 3rdparty
#include <boost/stacktrace.hpp>

using namespace callisto::framework;


#pragma region ConstructAndDestruct

CALLISTO_CALL DetailException::DetailException(
	std::string& error_message, 
	const char* file_name, 
	int line
)
{
	std::stringstream ss;
	ss << "In file:" << file_name << std::endl;
	ss << "At line:" << line << std::endl;
	ss << "Call stack:\n";
	auto stacktrace = boost::stacktrace::stacktrace();
	for (auto& frame : stacktrace)
	{
		ss << "(" << frame.address() << "):" << frame.name() << std::endl;
	}
	ss << "Error message:\n" << error_message << std::endl;
	this->error_message = ss.str();
}

#pragma endregion

#pragma region Methods

const char* CALLISTO_CALL DetailException::what() const noexcept
{
	return this->error_message.c_str();
}

const std::string& CALLISTO_CALL DetailException::get_error_message() const
{
	return this->error_message;
}

void CALLISTO_CALL DetailException::move_message_to(
	std::string& message
)
{
	message = std::move(this->error_message);
}

#pragma endregion