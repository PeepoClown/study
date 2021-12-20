#include "Intern.hpp"

Intern::UndefinedFormException::UndefinedFormException(void)
	: errorMsg("")
{ }

Intern::UndefinedFormException::~UndefinedFormException() _NOEXCEPT
{ }

Intern::UndefinedFormException::UndefinedFormException(const std::string &errorMsg)
	: errorMsg(errorMsg)
{ }

Intern::UndefinedFormException::UndefinedFormException(const UndefinedFormException
	&undefinedFormException)
{
	*this = undefinedFormException;
}

Intern::UndefinedFormException&	Intern::UndefinedFormException::operator= (const
	UndefinedFormException &undefinedFormException)
{
	this->errorMsg = undefinedFormException.errorMsg;
	return (*this);
}

const char*	Intern::UndefinedFormException::what(void) const _NOEXCEPT
{
	return (this->errorMsg.c_str());
}
