#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
{
	this->type = "SC4V-TP";
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << name << " died" << std::endl;
}

ScavTrap::ScavTrap(const std::string &name)
{
	std::cout << "ScavTrap " << name << " come to fight" << std::endl;
	this->hp = 100;
	this->hpMax = 100;
	this->ep = 50;
	this->epMax = 50;
	this->level = 1;
	this->name = name;
	this->meleeDmg = 20;
	this->rangeDmg = 15;
	this->armorRed = 3;
	this->type = "SC4V-TP";
}

ScavTrap::ScavTrap(const ScavTrap &scavTrap)
{
	std::cout << "once again " << "ScavTrap " << name << " come to fight" << std::endl;
	*this = scavTrap;
}

ScavTrap&	ScavTrap::operator= (const ScavTrap &scavTrap)
{
	this->hp = scavTrap.hp;
	this->hpMax = scavTrap.hpMax;
	this->ep = scavTrap.ep;
	this->epMax = scavTrap.epMax;
	this->level = scavTrap.level;
	this->name = scavTrap.name;
	this->meleeDmg = scavTrap.meleeDmg;
	this->rangeDmg = scavTrap.rangeDmg;
	this->armorRed = scavTrap.armorRed;
	this->type = scavTrap.type;
	return (*this);
}

void	ScavTrap::challengeNewcomer(const std::string &target)
{
	const char	*challenges[] = {
		"F*CK YOU, LEATHERMAN!",
		"OH SHIT, I'M SORRY!",
		"THANK YOU, SIR!",
		"GET YOUR ASS DOWN HERE NOW BOY!"
	};

	std::cout << this->name << " tell to " << target << " : ";
	srand(time(NULL));
	std::cout << "♂" << challenges[rand() % 4] << "♂";
	std::cout << std::endl;
}
