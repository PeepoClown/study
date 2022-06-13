#include "Character.hpp"

Character::Character(void)
	: name(""), ap(0), weapon(nullptr)
{ }

Character::~Character()
{ }

Character::Character(const std::string &name)
	: name(name), ap(40), weapon(nullptr)
{ }

Character::Character(const Character &character)
{
	*this = character;
}

Character&	Character::operator= (const Character &character)
{
	this->name = character.name;
	this->ap = character.ap;
	this->weapon = character.weapon;
	return (*this);
}

std::string	Character::getName(void) const
{
	return (this->name);
}

int			Character::getAP(void) const
{
	return (this->ap);
}

AWeapon*	Character::getWeapon(void) const
{
	return (this->weapon);
}

void	Character::recoverAP(void)
{
	if (this->ap <= 30)
		this->ap += 10;
	else
		this->ap = 40;
}

void	Character::equip(AWeapon *weapon)
{
	this->weapon = weapon;
}

void	Character::attack(Enemy *enemy)
{
	if (this->ap - this->weapon->getAPCost() >= 0)
	{
		std::cout << this->name << " attacks " << enemy->getType()
			<< " with a " << this->weapon->getName() << std::endl;
		this->weapon->attack();
		enemy->takeDamage(this->weapon->getDamage());
		this->ap -= this->weapon->getAPCost();
	}
	else
		std::cout << "Not enought AP" << std::endl;
}

std::ostream&	operator<< (std::ostream &out, const Character &character)
{
	out << character.getName() << " has " << character.getAP()
		<< " AP and ";
	if (character.getWeapon() != nullptr)
		out << "wields a " << character.getWeapon()->getName() << std::endl;
	else
		out << "is unarmed" << std::endl;
	return (out);
}
