#include "Cure.hpp"

Cure::Cure(void)
	: AMateria("cure")
{ }

Cure::~Cure()
{ }

Cure::Cure(const Cure &cure)
{
	*this = cure;
}

Cure&	Cure::operator= (const Cure &cure)
{
	this->xp = cure.xp;
	this->type = cure.type;
	return (*this);
}

AMateria*	Cure::clone(void) const
{
	return (new Cure(*this));
}

void		Cure::use(ICharacter &target)
{
	AMateria::use(target);
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}
