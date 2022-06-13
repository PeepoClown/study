#include "Form.hpp"

Form::GradeTooLowException::GradeTooLowException(void)
	: errorMsg("")
{ }

Form::GradeTooLowException::~GradeTooLowException() _NOEXCEPT
{ }

Form::GradeTooLowException::GradeTooLowException(const std::string &errorMsg)
	: errorMsg(errorMsg)
{ }

Form::GradeTooLowException::GradeTooLowException(const GradeTooLowException
	&gradeTooLowException)
{
	*this = gradeTooLowException;
}

Form::GradeTooLowException&	Form::GradeTooLowException::operator= (const
	GradeTooLowException &gradeTooLowException)
{
	this->errorMsg = gradeTooLowException.errorMsg;
	return (*this);
}

const char*	Form::GradeTooLowException::what(void) const _NOEXCEPT
{
	return (this->errorMsg.c_str());
}
