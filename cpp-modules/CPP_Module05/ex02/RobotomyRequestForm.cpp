#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void)
	: Form("robotomy request form", 72, 45), target("")
{ }

RobotomyRequestForm::~RobotomyRequestForm()
{ }

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
	: Form("robotomy request form", 72, 45), target(target)
{ }

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm
	&robotomyRequestForm)
	: Form("robotomy request form", 72, 45)
{
	*this = robotomyRequestForm;
}

RobotomyRequestForm&	RobotomyRequestForm::operator= (const RobotomyRequestForm
			&robotomyRequestForm)
{
	this->target = robotomyRequestForm.target;
	return (*this);
}

const std::string&	RobotomyRequestForm::getTarget(void) const
{
	return (this->target);
}

void	RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	Form::execute(executor);
	std::cout << "\a\a\aVJ VJ VJ VJ VJ..." << std::endl;
	srand(time(NULL));
	if (rand() % 2 == 0)
		std::cout << "robotomized of " << this->target << " successfully" << std::endl;
	else
		std::cout << "robotomized of " << this->target << " failed" << std::endl;
}
