#include "Intern.hpp"

Intern::Intern(void)
{ }

Intern::~Intern(void)
{ }

Intern::Intern(const Intern &intern)
{
	*this = intern;
}

Intern&	Intern::operator= (const Intern &intern)
{
	static_cast<void>(intern);
	return (*this);
}

Form*	Intern::makeForm(const std::string &formName, const std::string &target)
{
	const std::string	formNames[] = {
		"presidential pardon form",
		"robotomy request form",
		"shrubbery creation form"
	};

	int		i = 0;
	for (i = 0; i < 3; i++)
		if (formName == formNames[i])
			break ;
	if (i == 3)
		throw UndefinedFormException(formName + " is undefined");
	std::cout << "Intern creates form : " << formName << std::endl;
	if (i == 0)
		return (new PresidentialPardonForm(target));
	else if (i == 1)
		return (new RobotomyRequestForm(target));
	else
		return (new ShrubberyCreationForm(target));
}
