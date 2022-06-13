#include "Bureaucrat.hpp"

Bureaucrat::GradeTooLowException::GradeTooLowException(void)
	: errorMsg("")
{ }

Bureaucrat::GradeTooLowException::~GradeTooLowException() _NOEXCEPT
{ }

Bureaucrat::GradeTooLowException::GradeTooLowException(const std::string &errorMsg)
	: errorMsg(errorMsg)
{ }

Bureaucrat::GradeTooLowException::GradeTooLowException(const GradeTooLowException
	&gradeTooLowException)
{
	*this = gradeTooLowException;
}

Bureaucrat::GradeTooLowException&	Bureaucrat::GradeTooLowException::operator= (const
	GradeTooLowException &gradeTooLowException)
{
	this->errorMsg = gradeTooLowException.errorMsg;
	return (*this);
}

const char*	Bureaucrat::GradeTooLowException::what(void) const _NOEXCEPT
{
	return (this->errorMsg.c_str());
}
