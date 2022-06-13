#include "Victim.hpp"

Victim::Victim(void)
	: name("")
{ }

Victim::~Victim()
{
	std::cout << "Victim " << this->name << " just died for no apparent reason!"
		<< std::endl;
}

Victim::Victim(const std::string &name)
	: name(name)
{
	std::cout << "Some random victim called " << this->name << " just appeared!"
		<< std::endl;
}

Victim::Victim(const Victim &victim)
{
	*this = victim;
	std::cout << "Some random victim called " << this->name << " just appeared!"
		<< std::endl;
}

Victim&	Victim::operator= (const Victim &victim)
{
	this->name = victim.name;
	return (*this);
}

std::string	Victim::getName(void) const
{
	return (this->name);
}

void	Victim::getPolymorphed(void) const
{
	std::cout << this->name << " has been turned into a cute little sheep!"
		<< std::endl;
}

std::ostream&	operator<< (std::ostream &out, const Victim &victim)
{
	out << "I'm " << victim.getName() << " and I like otters!" << std::endl;
	return (out);
}
