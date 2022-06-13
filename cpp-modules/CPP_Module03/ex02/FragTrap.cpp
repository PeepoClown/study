#include "FragTrap.hpp"

FragTrap::FragTrap(void)
{
	this->type = "FR4G-TP";
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << name << " died" << std::endl;
}

FragTrap::FragTrap(const std::string &name)
{
	std::cout << "FragTrap " << name << " come to fight" << std::endl;
	this->hp = 100;
	this->hpMax = 100;
	this->ep = 100;
	this->epMax = 100;
	this->level = 1;
	this->name = name;
	this->meleeDmg = 30;
	this->rangeDmg = 20;
	this->armorRed = 5;
	this->type = "FR4G-TP";
}

FragTrap::FragTrap(const FragTrap &fragTrap)
{
	std::cout << "once again " << "FragTrap " << name << " come to fight" << std::endl;
	*this = fragTrap;
}

FragTrap&	FragTrap::operator= (const FragTrap &fragTrap)
{
	this->hp = fragTrap.hp;
	this->hpMax = fragTrap.hpMax;
	this->ep = fragTrap.ep;
	this->epMax = fragTrap.epMax;
	this->level = fragTrap.level;
	this->name = fragTrap.name;
	this->meleeDmg = fragTrap.meleeDmg;
	this->rangeDmg = fragTrap.rangeDmg;
	this->armorRed = fragTrap.armorRed;
	this->type = fragTrap.type;
	return (*this);
}

size_t	FragTrap::vaulthunter_dot_exe(const std::string &target)
{
	size_t	total_dmg = 0;

	if (this->ep < 25)
		std::cout << "Not enought energy points!" << std::endl;
	else
	{
		srand(time(NULL));
		int		random = rand() % 5;

		std::cout << "Random attack : ";
		if (random == 0)
		{
			std::cout << "For the Lich King!" << std::endl;
			total_dmg += meleeAttack(target);
		}
		else if (random == 1)
		{
			std::cout << "Die Fool." << std::endl;
			total_dmg += rangedAttack(target);
		}
		else if (random == 2)
		{
			std::cout << "I'll make sure you suffer." << std::endl;
			total_dmg += meleeAttack(target);
			total_dmg += meleeAttack(target);
			total_dmg += meleeAttack(target);
		}
		else if (random == 3)
		{
			std::cout << "Glory to the Scourge!" << std::endl;
			total_dmg += rangedAttack(target);
			total_dmg += rangedAttack(target);
		}
		else
		{
			std::cout << "Taste this!" << std::endl;
			total_dmg += rangedAttack(target);
			total_dmg += meleeAttack(target);
		}
		if (static_cast<int>(this->ep) - 25 >= 0)
			this->ep -= 25;
		else
			this->ep = 0;
	}
	return (total_dmg);
}
