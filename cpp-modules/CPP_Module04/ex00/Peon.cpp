#include "Peon.hpp"

Peon::Peon(void)
{ }

Peon::~Peon()
{
	std::cout << "Bleuark..." << std::endl;
}

Peon::Peon(const std::string &name)
	: Victim(name)
{
	std::cout << "Zog zog." << std::endl;
}

Peon::Peon(const Peon &peon)
{
	*this = peon;
	std::cout << "Some random victim called " << this->name << " just appeared!"
		<< std::endl;
}

Peon&	Peon::operator= (const Peon &peon)
{
	this->name = peon.name;
	return (*this);
}

void	Peon::getPolymorphed(void) const
{
	std::cout << this->name << " has been turned into a pink pony!"
		<< std::endl;
}
