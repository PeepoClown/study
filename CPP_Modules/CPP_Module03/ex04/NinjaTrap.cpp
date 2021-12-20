#include "NinjaTrap.hpp"

NinjaTrap::NinjaTrap(void)
{
	std::cout << "NinjaTrap created" << std::endl;
	this->ep = 120;
	this->epMax = 120;
	this->level = 1;
	this->name = "";
	this->meleeDmg = 60;
	this->type = "Ninj4-TP";
}

NinjaTrap::~NinjaTrap()
{
	std::cout << "NinjaTrap removed" << std::endl;
}

NinjaTrap::NinjaTrap(const std::string &name)
{
	std::cout << "NinjaTrap created" << std::endl;
	this->hp = 60;
	this->hpMax = 60;
	this->ep = 120;
	this->epMax = 120;
	this->level = 1;
	this->name = name;
	this->meleeDmg = 60;
	this->rangeDmg = 5;
	this->armorRed = 0;
	this->type = "Ninj4-TP";
}

NinjaTrap::NinjaTrap(const NinjaTrap &ninjaTrap)
{
	std::cout << "NinjaTrap created" << std::endl;
	*this = ninjaTrap;
}

NinjaTrap&	NinjaTrap::operator= (const NinjaTrap &ninjaTrap)
{
	this->hp = ninjaTrap.hp;
	this->hpMax = ninjaTrap.hpMax;
	this->ep = ninjaTrap.ep;
	this->epMax = ninjaTrap.epMax;
	this->level = ninjaTrap.level;
	this->name = ninjaTrap.name;
	this->meleeDmg = ninjaTrap.meleeDmg;
	this->rangeDmg = ninjaTrap.rangeDmg;
	this->armorRed = ninjaTrap.armorRed;
	this->type = ninjaTrap.type;
	return (*this);
}

size_t	NinjaTrap::ninjaShoebox(const FragTrap &fragTrap)
{
	std::cout << this->name << " with type " << this->getType() << " attacked "
		<< fragTrap.getName() << " with type " << fragTrap.getType() << std::endl;
	return (meleeAttack(fragTrap.getName()));
}

size_t	NinjaTrap::ninjaShoebox(const ScavTrap &scavTrap)
{
	std::cout << this->name << " with type " << this->getType() << " attacked "
		<< scavTrap.getName() << " with type " << scavTrap.getType() << std::endl;
	return (rangedAttack(scavTrap.getName()));
}

size_t	NinjaTrap::ninjaShoebox(const NinjaTrap &ninjaTrap)
{
	std::cout << this->name << " with type " << this->getType() << " attacked "
		<< ninjaTrap.getName() << " with type " << ninjaTrap.getType() << std::endl;
	return (meleeAttack(ninjaTrap.getName()) +
		rangedAttack(ninjaTrap.getName()));
}
