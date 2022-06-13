#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void)
	: Form("presidential pardon form", 25, 5), target("")
{ }

PresidentialPardonForm::~PresidentialPardonForm()
{ }

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
	: Form("presidential pardon form", 25, 5), target(target)
{ }

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm
	&presidentialPardonForm)
	: Form("presidential pardon form", 25, 5)
{
	*this = presidentialPardonForm;
}

PresidentialPardonForm&	PresidentialPardonForm::operator= (const PresidentialPardonForm
			&presidentialPardonForm)
{
	this->target = presidentialPardonForm.target;
	return (*this);
}

const std::string&	PresidentialPardonForm::getTarget(void) const
{
	return (this->target);
}

void	PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	Form::execute(executor);
	std::cout << this->target << " has been pardoned by Zafod Beeblebrox" << std::endl;
}