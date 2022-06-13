#ifndef INTERN_HPP
#define INTERN_HPP

#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <string>
#include <exception>

class	Intern
{
	private :
		class UndefinedFormException : public std::exception
		{
			private :
				std::string	errorMsg;
			public :
				UndefinedFormException(void);
				virtual ~UndefinedFormException() _NOEXCEPT;
				UndefinedFormException(const std::string &errorMsg);
				UndefinedFormException(const UndefinedFormException &undefinedFormException);

				UndefinedFormException&	operator= (const UndefinedFormException
					&undefinedFormException);

				const char*	what(void) const _NOEXCEPT;
		};
	public :
		Intern(void);
		~Intern();
		Intern(const Intern &intern);

		Intern&	operator= (const Intern &intern);

		Form*	makeForm(const std::string &formName, const std::string &target);
};

#endif
