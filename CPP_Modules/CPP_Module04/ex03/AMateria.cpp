#include "AMateria.hpp"

AMateria::AMateria(void)
	: xp(0), type("")
{ }

AMateria::~AMateria()
{ }

AMateria::AMateria(const std::string &type)
	: xp(0), type(type)
{ }

AMateria::AMateria(const AMateria &materia)
{
	*this = materia;
}

AMateria&	AMateria::operator= (const AMateria &materia)
{
	this->xp = materia.xp;
	this->type = materia.type;
	return (*this);
}

const std::string&	AMateria::getType(void) const
{
	return (type);
}

unsigned int		AMateria::getXP(void) const
{
	return (xp);
}

void				AMateria::use(ICharacter &target)
{
	static_cast<void>(target);
	this->xp += 10;
}
