#include "PlasmaRifle.hpp"

PlasmaRifle::PlasmaRifle(void)
	: AWeapon("Plasma Rifle", 5, 21)
{ }

PlasmaRifle::~PlasmaRifle()
{ }

PlasmaRifle::PlasmaRifle(const std::string &name, int apcost, int damage)
	: AWeapon(name, apcost, damage)
{ }

PlasmaRifle::PlasmaRifle(const PlasmaRifle &plasmaRifle)
{
	*this = plasmaRifle;
}

PlasmaRifle&	PlasmaRifle::operator= (const PlasmaRifle &plasmaRifle)
{
	this->name = plasmaRifle.name;
	this->apcost = plasmaRifle.apcost;
	this->damage = plasmaRifle.damage;
	return (*this);
}

void	PlasmaRifle::attack(void) const
{
	std::cout << "* piouuu piouuu piouuu *" << std::endl;
}
