#include "Bureaucrat.hpp"

Bureaucrat::GradeTooHighException::GradeTooHighException(void)
	: errorMsg("")
{ }

Bureaucrat::GradeTooHighException::~GradeTooHighException() _NOEXCEPT
{ }

Bureaucrat::GradeTooHighException::GradeTooHighException(const std::string &errorMsg)
	: errorMsg(errorMsg)
{ }

Bureaucrat::GradeTooHighException::GradeTooHighException(const GradeTooHighException
	&gradeTooHighException)
{
	*this = gradeTooHighException;
}

Bureaucrat::GradeTooHighException&	Bureaucrat::GradeTooHighException::operator= (const
	GradeTooHighException &gradeTooHighException)
{
	this->errorMsg = gradeTooHighException.errorMsg;
	return (*this);
}

const char*	Bureaucrat::GradeTooHighException::what(void) const _NOEXCEPT
{
	return (this->errorMsg.c_str());
}
