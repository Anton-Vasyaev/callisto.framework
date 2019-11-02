// parent header
#include <Callisto/Framework/Exception/DetailException.hpp>
// std
#include <sstream>
// 3rdparty
#include <boost/stacktrace.hpp>



namespace Callisto::Framework
{

	DetailException::DetailException(
		std::string& errorMessage, 
		const char* fileName, 
		int line
	)
	{
		std::stringstream ss;
		ss << "In file:" << fileName << std::endl;
		ss << "At line:" << line << std::endl;
		ss << "Call stack:\n" << boost::stacktrace::stacktrace() << std::endl;
		ss << "Error message:\n" << errorMessage << std::endl;
		this->errorMessage = ss.str();
	}

	const char* CALLISTO_CALL DetailException::what() const
	{
		return this->errorMessage.c_str();
	}

	const std::string& CALLISTO_CALL DetailException::GetErrorMessage() const
	{
		return this->errorMessage;
	}

	void CALLISTO_CALL DetailException::MoveMessageTo(std::string& message)
	{
		message = std::move(this->errorMessage);
	}
}