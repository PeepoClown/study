#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

class	Bureaucrat
{
	private :
		std::string	name;
		int			grade;
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
		Bureaucrat(void);
		~Bureaucrat();
		Bureaucrat(const std::string &name, int grade);
		Bureaucrat(const Bureaucrat &bureaucrat);

		Bureaucrat&	operator= (const Bureaucrat &bureaucrat);

		const std::string&	getName(void) const;
		int					getGrade(void) const;

		void	upGrade(void);
		void	downGrade(void);
};

std::ostream&	operator<< (std::ostream &out, const Bureaucrat &bureaucrat);

#endif
