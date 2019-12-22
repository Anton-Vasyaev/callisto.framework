//
// Copyright (c) 2019
// Vasyaev Anton
//

#ifndef CALLISTO_FRAMEWORK_DETAIL_EXCEPTION_HPP
#define CALLISTO_FRAMEWORK_DETAIL_EXCEPTION_HPP

// std
#include <string>
#include <exception>
// project
#include <callisto/framework/native/lib_export.h>


namespace callisto::framework
{
	class CALLISTO_EXPORT DetailException : public std::exception
	{
	private:
		std::string error_message;

	public:
		// construct and destruct
		CALLISTO_CALL DetailException(
			std::string& error_message, 
			const char* file_name, 
			int line
		);

		// methods
		virtual const char* CALLISTO_CALL what() const noexcept override;

		const std::string& CALLISTO_CALL get_error_message() const;

		void CALLISTO_CALL move_message_to(std::string& message);
	};
}

#define THROW_DETAIL(ss) throw callisto::framework::DetailException(ss, __FILE__, __LINE__);


#endif