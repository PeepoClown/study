#include "HumanB.hpp"

HumanB::HumanB(void)
	: name(""), weapon(nullptr)
{ }

HumanB::HumanB(const std::string &name)
	: name(name), weapon(nullptr)
{ }

void	HumanB::attack(void)
{
	std::cout << this->name << " attacks with his " << this->weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}
