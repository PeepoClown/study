#include "Sorcerer.hpp"

Sorcerer::Sorcerer(void)
	: name(""), title("")
{ }

Sorcerer::~Sorcerer()
{
	std::cout << this->name << ", "
		<< this->title << ", is dead. Consequences will never be the same!" << std::endl;
}

Sorcerer::Sorcerer(const std::string &name, const std::string &title)
	: name(name), title(title)
{
	std::cout << this->name << ", " << this->title << ", is born!" << std::endl;
}

Sorcerer::Sorcerer(const Sorcerer &sorcerer)
{
	this->name = sorcerer.name;
	this->title = sorcerer.title;
	std::cout << this->name << ", " << this->title << ", is born!" << std::endl;
}

Sorcerer&	Sorcerer::operator= (const Sorcerer &sorcerer)
{
	this->name = sorcerer.name;
	this->title = sorcerer.title;
	return (*this);
}

std::string	Sorcerer::getName(void) const
{
	return (this->name);
}

std::string	Sorcerer::getTitle(void) const
{
	return (this->title);
}

void	Sorcerer::polymorph(const Victim &victim) const
{
	victim.getPolymorphed();
}

std::ostream&	operator<< (std::ostream &out, const Sorcerer &sorcerer)
{
	out << "I am " << sorcerer.getName() << ", " << sorcerer.getTitle()
		<< ", and I like ponies!" << std::endl;
	return (out);
}
