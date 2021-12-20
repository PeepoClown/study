#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
	: hp(0), hpMax(0), ep(0), epMax(0), level(0),
	name(""), meleeDmg(0), rangeDmg(0), armorRed(0)
{ }

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << name << " died" << std::endl;
}

ScavTrap::ScavTrap(const std::string &name)
	: hp(100), hpMax(100), ep(50), epMax(50), level(1),
	name(name), meleeDmg(20), rangeDmg(15), armorRed(3)
{
	std::cout << "ScavTrap " << name << " come to fight" << std::endl;
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
	return (*this);
}

std::string	ScavTrap::getName(void) const
{
	return (this->name);
}

size_t	ScavTrap::rangedAttack(const std::string &target)
{
	std::cout << "SC4V-TP " << this->name << " attacks " << target << " at range, causing "
		<< this->rangeDmg << " points of damage!" << std::endl;
	return (this->rangeDmg);
}

size_t	ScavTrap::meleeAttack(const std::string &target)
{
	std::cout << "SK4V-TP " << this->name << " attacks " << target << " at melee, causing "
		<< this->meleeDmg << " points of damage!" << std::endl;
	return (this->meleeDmg);
}

void	ScavTrap::takeDamage(unsigned int amount)
{
	std::cout << "SK4V-TP " << this->name << " take " << amount << " points of damage!";
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

void	ScavTrap::beRepaired(unsigned int amount)
{
	std::cout << "SK4V-TP " << this->name << " repair " << amount << " points of health!";
	if (amount + this->hp < this->hpMax)
		this->hp += amount;
	else
		this->hp = this->hpMax;
	std::cout << " Now he have " << this->hp << " health points." << std::endl;
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
