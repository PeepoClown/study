#include "SuperMutant.hpp"

SuperMutant::SuperMutant(void)
	: Enemy(170, "Super Mutant")
{
	std::cout << "Gaaah. Me want smash heads!" << std::endl;
}

SuperMutant::~SuperMutant()
{ }

SuperMutant::SuperMutant(int hp, const std::string &type)
	: Enemy(hp, type)
{
	std::cout << "Gaaah. Me want smash heads!" << std::endl;
}

SuperMutant::SuperMutant(const SuperMutant &superMutant)
{
	std::cout << "Gaaah. Me want smash heads!" << std::endl;
	*this = superMutant;
}

SuperMutant&	SuperMutant::operator= (const SuperMutant &superMutant)
{
	this->hp = superMutant.hp;
	this->type = superMutant.type;
	return (*this);
}

void	SuperMutant::takeDamage(int damage)
{
	Enemy::takeDamage(damage - 3);

	if (this->hp == 0)
		std::cout << "Aaargh..." << std::endl;
	else
		std::cout << "Now " << this->type << " have a "
			<< this->hp << " hit points" << std::endl;
}
