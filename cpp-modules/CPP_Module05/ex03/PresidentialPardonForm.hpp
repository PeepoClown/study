#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <string>
#include <exception>

class	PresidentialPardonForm : public Form
{
	private :
		std::string	target;
	public :
		PresidentialPardonForm(void);
		~PresidentialPardonForm();
		PresidentialPardonForm(const std::string &target);
		PresidentialPardonForm(const PresidentialPardonForm &presidentialPardonForm);

		PresidentialPardonForm&	operator= (const PresidentialPardonForm
			&presidentialPardonForm);

		const std::string&	getTarget(void) const;

		void	execute(const Bureaucrat &executor) const;
};

#endif
