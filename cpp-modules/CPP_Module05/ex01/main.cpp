#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>
#include <exception>

int		main(void)
{
	Bureaucrat b1("Stepan Petrovich", 3);

	Form f1("important form", 100, 100);
	Form f2("very important form", 3, 3);
	Form f3("ultra very mega important form", 2, 2);

	std::cout << f1 << f2 << f3;

	try
	{
		f1.beSigned(b1);
	}
	catch(const std::exception &exception)
	{
		std::cerr << exception.what() << std::endl;
		std::cout << "Type of exception : " << typeid(exception).name() << std::endl;
	}

	try
	{
		f2.beSigned(b1);
	}
	catch(const std::exception &exception)
	{
		std::cerr << exception.what() << std::endl;
		std::cout << "Type of exception : " << typeid(exception).name() << std::endl;
	}

	try
	{
		f3.beSigned(b1);
	}
	catch(const std::exception &exception)
	{
		std::cerr << exception.what() << std::endl;
		std::cout << "Type of exception : " << typeid(exception).name() << std::endl;
	}

	try
	{
		b1.upGrade();
		f3.beSigned(b1);
	}
	catch(const std::exception &exception)
	{
		std::cerr << exception.what() << std::endl;
		std::cout << "Type of exception : " << typeid(exception).name() << std::endl;
	}

	try
	{
		Form f4("form", 151, 151);
	}
	catch(const std::exception &exception)
	{
		std::cerr << exception.what() << std::endl;
		std::cout << "Type of exception : " << typeid(exception).name() << std::endl;
	}

	try
	{
		Form f4("form", 0, 0);
	}
	catch(const std::exception &exception)
	{
		std::cerr << exception.what() << std::endl;
		std::cout << "Type of exception : " << typeid(exception).name() << std::endl;
	}

	return (0);
}
