#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <fstream>
#include <string>
#include <exception>

class	ShrubberyCreationForm : public Form
{
	private :
		std::string	target;
	public :
		ShrubberyCreationForm(void);
		~ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string &target);
		ShrubberyCreationForm(const ShrubberyCreationForm &shrubberyCreationForm);

		ShrubberyCreationForm&	operator= (const ShrubberyCreationForm
			&shrubberyCreationForm);

		const std::string&	getTarget(void) const;

		void	execute(const Bureaucrat &executor) const;
};

#endif
