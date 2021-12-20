#include "FragTrap.hpp"

FragTrap::FragTrap(void)
	: hp(0), hpMax(0), ep(0), epMax(0), level(0),
	name(""), meleeDmg(0), rangeDmg(0), armorRed(0)
{ }

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << name << " died" << std::endl;
}

FragTrap::FragTrap(const std::string &name)
	: hp(100), hpMax(100), ep(100), epMax(100), level(1),
	name(name), meleeDmg(30), rangeDmg(20), armorRed(5)
{
	std::cout << "FragTrap " << name << " come to fight" << std::endl;
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
	return (*this);
}

std::string	FragTrap::getName(void) const
{
	return (this->name);
}

size_t	FragTrap::rangedAttack(const std::string &target)
{
	std::cout << "FR4G-TP " << this->name << " attacks " << target << " at range, causing "
		<< this->rangeDmg << " points of damage!" << std::endl;
	return (this->rangeDmg);
}

size_t	FragTrap::meleeAttack(const std::string &target)
{
	std::cout << "FR4G-TP " << this->name << " attacks " << target << " at melee, causing "
		<< this->meleeDmg << " points of damage!" << std::endl;
	return (this->meleeDmg);
}

void	FragTrap::takeDamage(unsigned int amount)
{
	std::cout << "FR4G-TP " << this->name << " take " << amount << " points of damage!";
	if (amount <= this->armorRed)
	{
		std::cout << std::endl;
		return ;
	}
	if (static_cast<int>(this->hp) - static_cast<int>(amount
		- this->armorRed) >= 0)
		this->hp -= amount - this->armorRed;
	else
		this->hp = 0;
	std::cout << " Now he have " << this->hp << " health points." << std::endl;
}

void	FragTrap::beRepaired(unsigned int amount)
{
	std::cout << "FR4G-TP " << this->name << " repair " << amount << " points of health!";
	if (amount + this->hp < this->hpMax)
		this->hp += amount;
	else
		this->hp = this->hpMax;
	std::cout << " Now he have " << this->hp << " health points." << std::endl;
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
