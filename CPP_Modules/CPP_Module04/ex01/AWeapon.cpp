#include "AWeapon.hpp"

AWeapon::AWeapon(void)
	: name(""), apcost(0), damage(0)
{ }

AWeapon::~AWeapon()
{ }

AWeapon::AWeapon(const std::string &name, int apcost, int damage)
	: name(name), apcost(apcost), damage(damage)
{ }

AWeapon::AWeapon(const AWeapon &weapon)
{
	*this = weapon;
}

AWeapon&	AWeapon::operator= (const AWeapon &weapon)
{
	this->name = weapon.name;
	this->apcost = weapon.apcost;
	this->damage = weapon.damage;
	return (*this);
}

std::string	AWeapon::getName(void) const
{
	return (this->name);
}

int			AWeapon::getAPCost(void) const
{
	return (this->apcost);
}

int			AWeapon::getDamage(void) const
{
	return (this->damage);
}
