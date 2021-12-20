#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
	: hp(0), hpMax(0), ep(0), epMax(0), level(0),
	name(""), meleeDmg(0), rangeDmg(0), armorRed(0)
{
	std::cout << "ClapTrap created" << std::endl;
	this->type = "CL4P-TP";
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap removed" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &clapTrap)
{
	std::cout << "ClapTrap created" << std::endl;
	*this = clapTrap;
}

ClapTrap&	ClapTrap::operator= (const ClapTrap &clapTrap)
{
	this->hp = clapTrap.hp;
	this->hpMax = clapTrap.hpMax;
	this->ep = clapTrap.ep;
	this->epMax = clapTrap.epMax;
	this->level = clapTrap.level;
	this->name = clapTrap.name;
	this->meleeDmg = clapTrap.meleeDmg;
	this->rangeDmg = clapTrap.rangeDmg;
	this->armorRed = clapTrap.armorRed;
	this->type = clapTrap.type;
	return (*this);
}

std::string	ClapTrap::getName(void) const
{
	return (this->name);
}

std::string	ClapTrap::getType(void) const
{
	return (this->type);
}

size_t	ClapTrap::rangedAttack(const std::string &target)
{
	std::cout << this->type << " " << this->name << " attacks " << target << " at range, causing "
		<< this->rangeDmg << " points of damage!" << std::endl;
	return (this->rangeDmg);
}

size_t	ClapTrap::meleeAttack(const std::string &target)
{
	std::cout << this->type << " " << this->name << " attacks " << target << " at melee, causing "
		<< this->meleeDmg << " points of damage!" << std::endl;
	return (this->meleeDmg);
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << this->type << " " << this->name << " take " << amount << " points of damage!";
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

void	ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << this->type << " " << this->name << " repair " << amount << " points of health!";
	if (amount + this->hp < this->hpMax)
		this->hp += amount;
	else
		this->hp = this->hpMax;
	std::cout << " Now he have " << this->hp << " health points." << std::endl;
}
