#include "Form.hpp"

Form::GradeTooHighException::GradeTooHighException(void)
	: errorMsg("")
{ }

Form::GradeTooHighException::~GradeTooHighException() _NOEXCEPT
{ }

Form::GradeTooHighException::GradeTooHighException(const std::string &errorMsg)
	: errorMsg(errorMsg)
{ }

Form::GradeTooHighException::GradeTooHighException(const GradeTooHighException
	&gradeTooHighException)
{
	*this = gradeTooHighException;
}

Form::GradeTooHighException&	Form::GradeTooHighException::operator= (const
	GradeTooHighException &gradeTooHighException)
{
	this->errorMsg = gradeTooHighException.errorMsg;
	return (*this);
}

const char*	Form::GradeTooHighException::what(void) const _NOEXCEPT
{
	return (this->errorMsg.c_str());
}
