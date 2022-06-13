#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "Intern.hpp"
#include <iostream>
#include <exception>

int		main(void)
{
	Intern	intern;

	Bureaucrat b1("Oleg Semenovich", 5);

	try
	{
		Form *form = intern.makeForm("presidential pardon form", "Pablo Escobar");
		form->beSigned(b1);
		form->execute(b1);
	}
	catch(const std::exception &exception)
	{
		std::cerr << exception.what() << std::endl;
		std::cout << "Type of exception : " << typeid(exception).name() << std::endl;
	}

	Bureaucrat b2("Victor Petrovich", 25);

	try
	{
		Form *form = intern.makeForm("robotomy request form", "Terminator");
		form->beSigned(b2);
		form->execute(b2);
	}
	catch(const std::exception &exception)
	{
		std::cerr << exception.what() << std::endl;
		std::cout << "Type of exception : " << typeid(exception).name() << std::endl;
	}

	Bureaucrat b3("Stepan Mickhailovich", 100);

	try
	{
		Form *form = intern.makeForm("shrubbery creation form", "house");
		form->beSigned(b3);
		form->execute(b3);
	}
	catch(const std::exception &exception)
	{
		std::cerr << exception.what() << std::endl;
		std::cout << "Type of exception : " << typeid(exception).name() << std::endl;
	}

	try
	{
		Form *form = intern.makeForm("tree creation form", "house");
		form->beSigned(b3);
		form->execute(b3);
	}
	catch(const std::exception &exception)
	{
		std::cerr << exception.what() << std::endl;
		std::cout << "Type of exception : " << typeid(exception).name() << std::endl;
	}


	return (0);
}
