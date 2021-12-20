#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>
#include <string>
#include <exception>

class	Form
{
	private :
		const std::string	name;
		bool				isSigned;
		const int			signGrade;
		const int			execGrade;
	private :
		class GradeTooHighException : public std::exception
		{
			private :
				std::string	errorMsg;
			public :
				GradeTooHighException(void);
				virtual ~GradeTooHighException() _NOEXCEPT;
				GradeTooHighException(const std::string &errorMsg);
				GradeTooHighException(const GradeTooHighException &gradeTooHighException);

				GradeTooHighException&	operator= (const GradeTooHighException
					&gradeTooHighException);

				const char*	what(void) const _NOEXCEPT;
		};
	private :
		class GradeTooLowException : public std::exception
		{
			private :
				std::string	errorMsg;
			public :
				GradeTooLowException(void);
				virtual ~GradeTooLowException() _NOEXCEPT;
				GradeTooLowException(const std::string &errorMsg);
				GradeTooLowException(const GradeTooLowException &gradeTooLowException);

				GradeTooLowException&	operator= (const GradeTooLowException
					&gradeTooLowException);

				const char*	what(void) const _NOEXCEPT;
		};
	public :
		Form(void);
		~Form();
		Form(const std::string &name, int signGrade, int execGrade);
		Form(const Form &form);

		Form&	operator= (const Form &form);

		const std::string&	getName(void) const;
		bool				getIsSigned(void) const;
		int					getSignGrade(void) const;
		int					getExexGrade(void) const;

		void	beSigned(const Bureaucrat &bureaucrat);
};

std::ostream&	operator<< (std::ostream& out, const Form &form);

#endif
