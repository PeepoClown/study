#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void)
	: name(""), grade(150)
{ }

Bureaucrat::~Bureaucrat()
{ }

Bureaucrat::Bureaucrat(const std::string &name, int grade)
	: name(name)
{
	if (grade < 1)
		throw GradeTooHighException("grade is invalid");
	if (grade > 150)
		throw GradeTooLowException("grade is invalid");
	this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat)
{
	*this = bureaucrat;
}

Bureaucrat&	Bureaucrat::operator= (const Bureaucrat &bureaucrat)
{
	this->name = bureaucrat.name;
	this->grade = bureaucrat.grade;
	return (*this);
}

const std::string&	Bureaucrat::getName(void) const
{
	return (this->name);
}

int					Bureaucrat::getGrade(void) const
{
	return (this->grade);
}

void	Bureaucrat::upGrade(void)
{
	if (this->grade - 1 < 1)
		throw GradeTooHighException("can't upgrade, " + this->name + " have max grade");
	this->grade--;
}

void	Bureaucrat::downGrade(void)
{
	if (this->grade + 1 > 150)
		throw GradeTooLowException("can't downgrade, " + this->name + " have min grade");
	this->grade++;
}

void	Bureaucrat::signForm(const std::string &formName) const
{
	std::cout << this->name << " signs " << formName << std::endl;
}

void	Bureaucrat::execForm(const std::string &formName) const
{
	std::cout << this->name << " execute " << formName << std::endl;
}

std::ostream&	operator<< (std::ostream &out, const Bureaucrat &bureaucrat)
{
	out << "Bureaucrat : name - " << bureaucrat.getName() << ", grade - "
		<< bureaucrat.getGrade() << std::endl;
	return (out);
}
