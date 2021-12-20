#include "Form.hpp"

Form::UnsignedFormException::UnsignedFormException(void)
	: errorMsg("")
{ }

Form::UnsignedFormException::~UnsignedFormException() _NOEXCEPT
{ }

Form::UnsignedFormException::UnsignedFormException(const std::string &errorMsg)
	: errorMsg(errorMsg)
{ }

Form::UnsignedFormException::UnsignedFormException(const UnsignedFormException
	&unsignedFormException)
{
	*this = unsignedFormException;
}

Form::UnsignedFormException&	Form::UnsignedFormException::operator= (const
	UnsignedFormException &unsignedFormException)
{
	this->errorMsg = unsignedFormException.errorMsg;
	return (*this);
}

const char*	Form::UnsignedFormException::what(void) const _NOEXCEPT
{
	return (this->errorMsg.c_str());
}
