#include "Weapon.hpp"

Weapon::Weapon(void)
	: type("")
{ }

Weapon::Weapon(const std::string &type)
	: type(type)
{ }

const std::string&	Weapon::getType(void)
{
	return (this->type);
}

void	Weapon::setType(const std::string &type)
{
	this->type = type;
}
