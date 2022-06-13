#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void)
	: Form("shrubbery creation form", 145, 137), target("")
{ }

ShrubberyCreationForm::~ShrubberyCreationForm()
{ }

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
	: Form("shrubbery creation form", 145, 137), target(target)
{ }

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm
	&shrubberyCreationForm)
	: Form("shrubbery creation form", 145, 137)
{
	*this = shrubberyCreationForm;
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator= (const ShrubberyCreationForm
			&shrubberyCreationForm)
{
	this->target = shrubberyCreationForm.target;
	return (*this);
}

const std::string&	ShrubberyCreationForm::getTarget(void) const
{
	return (this->target);
}

void	ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	std::ofstream	outFile(this->target + "_shrubbery", std::ofstream::out
		| std::ofstream::trunc);
	if (!outFile.is_open())
		throw std::runtime_error("can't open " + this->target + "_shrubbery");
	
	Form::execute(executor);
	outFile << "          .     .  .      +     .      .          ." << std::endl;
	outFile << "     .       .      .     #       .           ." << std::endl;
	outFile << "        .      .         ###            .      .      ." << std::endl;
	outFile << "      .      .   \"#:. .:##\"##:. .:#\"  .      ." << std::endl;
	outFile << "          .      . \"####\"###\"####\"  ." << std::endl;
	outFile << "       .     \"#:.    .:#\"###\"#:.    .:#\"  .        .       ." << std::endl;
	outFile << "  .             \"#########\"#########\"        .        ." << std::endl;
	outFile << "        .    \"#:.  \"####\"###\"####\"  .:#\"   .       ." << std::endl;
	outFile << "     .     .  \"#######\"\"##\"##\"\"#######\"                  ." << std::endl;
	outFile << "                .\"##\"#####\"#####\"##\"           .      ." << std::endl;
	outFile << "    .   \"#:. ...  .:##\"###\"###\"##:.  ... .:#\"     ." << std::endl;
	outFile << "      .     \"#######\"##\"#####\"##\"#######\"      .     ." << std::endl;
	outFile << "    .    .     \"#####\"\"#######\"\"#####\"    .      ." << std::endl;
	outFile << "            .     \"      000      \"    .     ." << std::endl;
	outFile << "       .         .   .   000     .        .       ." << std::endl;
	outFile << ".. .. ..................O000O........................ ...... ..." << std::endl;
	outFile.close();
}
