#include "Ice.hpp"

Ice::Ice(void)
	: AMateria("ice")
{ }

Ice::~Ice()
{ }

Ice::Ice(const Ice &ice)
{
	*this = ice;
}

Ice&	Ice::operator= (const Ice &ice)
{
	this->xp = ice.xp;
	this->type = ice.type;
	return (*this);
}

AMateria*	Ice::clone(void) const
{
	return (new Ice(*this));
}

void		Ice::use(ICharacter &target)
{
	AMateria::use(target);
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
