#include "Bureaucrat.hpp"
#include <iostream>
#include <exception>

int		main(void)
{
	Bureaucrat b1("Oleg Petrovich", 4);
	Bureaucrat b2("Vadim Grigorevich", 1);
	Bureaucrat b3("Nickolay Ivanovich", 150);

	std::cout << b1 << b2 << b3;

	std::cout << "upgrading " << b1.getName() << std::endl;
	try
	{
		b1.upGrade();
	}
	catch(const std::exception &exception)
	{
		std::cerr << exception.what() << std::endl;
		std::cout << "Type of exception : " << typeid(exception).name() << std::endl;
	}
	std::cout << "Now grade of " << b1.getName() << " is " << b1.getGrade() <<std::endl;

	std::cout << "downgrading " << b2.getName() << std::endl;
	try
	{
		b2.downGrade();
	}
	catch(const std::exception &exception)
	{
		std::cerr << exception.what() << std::endl;
		std::cout << "Type of exception : " << typeid(exception).name() << std::endl;
	}
	std::cout << "Now grade of " << b2.getName() << " is " << b2.getGrade() <<std::endl;

	try
	{
		Bureaucrat b4("Petr Ivanovich", 151);
	}
	catch(const std::exception &exception)
	{
		std::cerr << exception.what() << std::endl;
		std::cout << "Type of exception : " << typeid(exception).name() << std::endl;
	}

	try
	{
		Bureaucrat b4("Artem Ivanovich", 0);
	}
	catch(const std::exception &exception)
	{
		std::cerr << exception.what() << std::endl;
		std::cout << "Type of exception : " << typeid(exception).name() << std::endl;
	}

	try
	{
		b2.upGrade();
		b2.upGrade();
	}
	catch(const std::exception &exception)
	{
		std::cerr << exception.what() << std::endl;
		std::cout << "Type of exception : " << typeid(exception).name() << std::endl;
	}

	try
	{
		b3.downGrade();
	}
	catch(const std::exception &exception)
	{
		std::cerr << exception.what() << std::endl;
		std::cout << "Type of exception : " << typeid(exception).name() << std::endl;
	}

	return (0);
}
