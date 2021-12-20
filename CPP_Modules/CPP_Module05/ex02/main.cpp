#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <exception>

int		main(void)
{
	Bureaucrat b1("Stepan Petrovich", 3);

	ShrubberyCreationForm scf("yard");
	RobotomyRequestForm rrf("Android K");
	PresidentialPardonForm prf("Ramzan Achmatovich Kadyrov");

	try
	{
		scf.execute(b1);
	}
	catch(const std::exception &exception)
	{
		std::cerr << exception.what() << std::endl;
		std::cout << "Type of exception : " << typeid(exception).name() << std::endl;
	}

	try
	{
		scf.beSigned(b1);
		scf.execute(b1);
	}
	catch(const std::exception &exception)
	{
		std::cerr << exception.what() << std::endl;
		std::cout << "Type of exception : " << typeid(exception).name() << std::endl;
	}

	Bureaucrat b2("Nickolay Romanovich", 6);

	try
	{
		prf.beSigned(b2);
	}
	catch(const std::exception &exception)
	{
		std::cerr << exception.what() << std::endl;
		std::cout << "Type of exception : " << typeid(exception).name() << std::endl;
	}

	try
	{
		b2.upGrade();
		prf.beSigned(b2);
		prf.execute(b2);
	}
	catch(const std::exception &exception)
	{
		std::cerr << exception.what() << std::endl;
		std::cout << "Type of exception : " << typeid(exception).name() << std::endl;
	}

	Bureaucrat b3("Mikhail Olegovich", 20);

	try
	{
		rrf.beSigned(b3);
		rrf.execute(b3);
	}
	catch(const std::exception &exception)
	{
		std::cerr << exception.what() << std::endl;
		std::cout << "Type of exception : " << typeid(exception).name() << std::endl;
	}

	try
	{
		for (int i = 0; i < 55; i++)
			b3.downGrade();
		rrf.beSigned(b3);
		rrf.execute(b3);
	}
	catch(const std::exception &exception)
	{
		std::cerr << exception.what() << std::endl;
		std::cout << "Type of exception : " << typeid(exception).name() << std::endl;
	}

	return (0);
}
