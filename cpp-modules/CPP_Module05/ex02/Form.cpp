#include "Form.hpp"

Form::Form(void)
	: name(""), isSigned(false), signGrade(150), execGrade(150)
{ }

Form::~Form()
{ }

Form::Form(const std::string &name, int signGrade, int execGrade)
	: name(name), isSigned(false), signGrade(signGrade), execGrade(execGrade)
{
	if (this->signGrade < 1)
		throw GradeTooHighException("sign grade is invalid");
	if (this->signGrade > 150)
		throw GradeTooLowException("sign grade is invalid");

	if (this->execGrade < 1)
		throw GradeTooHighException("exec grade is invalid");
	if (this->execGrade > 150)
		throw GradeTooLowException("exec grade is invalid");
}

Form::Form(const Form &form)
	: name(form.name), signGrade(form.signGrade), execGrade(form.execGrade)
{
	this->isSigned = form.isSigned;
}

Form&	Form::operator= (const Form &form)
{
	this->isSigned = form.isSigned;
	return (*this);
}

const std::string&	Form::getName(void) const
{
	return (this->name);
}

bool				Form::getIsSigned(void) const
{
	return (this->isSigned);
}

int					Form::getSignGrade(void) const
{
	return (this->signGrade);
}

int					Form::getExexGrade(void) const
{
	return (this->execGrade);
}

void	Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->signGrade)
		throw GradeTooLowException("can't sign form " + this->name
			+ ", " + bureaucrat.getName() + " have too low grade");
	this->isSigned = true;
	bureaucrat.signForm(this->getName());
}

void	Form::execute(const Bureaucrat &executor) const
{
	if (this->isSigned == false)
		throw UnsignedFormException("Form : " + this->name + " is unsigned");
	if (executor.getGrade() > this->execGrade)
		throw GradeTooLowException("can't execute form " + this->name
			+ ", " + executor.getName() + " have too low grade");
	executor.execForm(this->getName());
}

std::ostream&	operator<< (std::ostream& out, const Form &form)
{
	out << "Form : " << form.getName() << ", signed status : " << std::boolalpha
		<< form.getIsSigned() << std::endl;
	return (out);
}
