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
#include <Callisto/Framework/Native/LibExport.h>


namespace Callisto::Framework
{
	class CALLISTO_EXPORT DetailException : public std::exception
	{
	private:
		std::string errorMessage;

	public:
		// construct and destruct
		DetailException(
			std::string& errorMessage, 
			const char* fileName, 
			int line
		);

		// methods
		virtual const char* CALLISTO_CALL what() const override;

		const std::string& CALLISTO_CALL GetErrorMessage() const;

		void CALLISTO_CALL MoveMessageTo(std::string& message);
	};
}

#define THROW_DETAIL(ss) throw Callisto::Framework::DetailException(ss, __FILE__, __LINE__);


#endif