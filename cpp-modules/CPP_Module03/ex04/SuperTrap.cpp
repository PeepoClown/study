#include "SuperTrap.hpp"

SuperTrap::SuperTrap(void)
{
	this->type = "$UPER-TP";
}

SuperTrap::~SuperTrap()
{
	std::cout << "SuperTrap " << name << " died" << std::endl;
}

SuperTrap::SuperTrap(const std::string &name)
{
	std::cout << "SuperTrap " << name << " come to fight" << std::endl;
	this->hp = FragTrap::hp;
	this->hpMax = FragTrap::hpMax;
	this->ep = NinjaTrap::ep;
	this->epMax = NinjaTrap::epMax;
	this->level = 1;
	this->name = name;
	this->meleeDmg = NinjaTrap::meleeDmg;
	this->rangeDmg = FragTrap::rangeDmg;
	this->armorRed = FragTrap::armorRed;
	this->type = "$UPER-TP";
}

SuperTrap::SuperTrap(const SuperTrap &superTrap)
{
	std::cout << "once again " << "SuperTrap " << name << " come to fight" << std::endl;
	*this = superTrap;
}

SuperTrap&	SuperTrap::operator= (const SuperTrap &superTrap)
{
	this->hp = superTrap.hp;
	this->hpMax = superTrap.hpMax;
	this->ep = superTrap.ep;
	this->epMax = superTrap.epMax;
	this->level = superTrap.level;
	this->name = superTrap.name;
	this->meleeDmg = superTrap.meleeDmg;
	this->rangeDmg = superTrap.rangeDmg;
	this->armorRed = superTrap.armorRed;
	this->type = superTrap.type;
	return (*this);
}
