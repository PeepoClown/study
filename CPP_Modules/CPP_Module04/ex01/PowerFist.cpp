#include "PowerFist.hpp"

PowerFist::PowerFist(void)
	: AWeapon("Power Fist", 8, 50)
{ }

PowerFist::~PowerFist()
{ }

PowerFist::PowerFist(const std::string &name, int apcost, int damage)
	: AWeapon(name, apcost, damage)
{ }

PowerFist::PowerFist(const PowerFist &powerFist)
{
	*this = powerFist;
}

PowerFist&	PowerFist::operator= (const PowerFist &powerFist)
{
	this->name = powerFist.name;
	this->apcost = powerFist.apcost;
	this->damage = powerFist.damage;
	return (*this);
}

void	PowerFist::attack(void) const
{
	std::cout << "* pschhh... SBAM! *" << std::endl;
}
