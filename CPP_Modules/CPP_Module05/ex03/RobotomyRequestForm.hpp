#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <string>
#include <exception>
#include <ctime>
#include <cstdlib>

class	RobotomyRequestForm : public Form
{
	private :
		std::string	target;
	public :
		RobotomyRequestForm(void);
		~RobotomyRequestForm();
		RobotomyRequestForm(const std::string &target);
		RobotomyRequestForm(const RobotomyRequestForm &robotomyRequestFormm);

		RobotomyRequestForm&	operator= (const RobotomyRequestForm
			&robotomyRequestForm);

		const std::string&	getTarget(void) const;

		void	execute(const Bureaucrat &executor) const;
};

#endif
