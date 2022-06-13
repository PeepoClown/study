#include "RadScorpion.hpp"

RadScorpion::RadScorpion(void)
	: Enemy(80, "RadScorpion")
{
	std::cout << "* click click click *" << std::endl;
}

RadScorpion::~RadScorpion()
{ }

RadScorpion::RadScorpion(int hp, const std::string &type)
	: Enemy(hp, type)
{
	std::cout << "* click click click *" << std::endl;
}

RadScorpion::RadScorpion(const RadScorpion &radScorpion)
{
	std::cout << "* click click click *" << std::endl;
	*this = radScorpion;
}

RadScorpion&	RadScorpion::operator= (const RadScorpion &radScorpion)
{
	this->hp = radScorpion.hp;
	this->type = radScorpion.type;
	return (*this);
}

void	RadScorpion::takeDamage(int damage)
{
	Enemy::takeDamage(damage);

	if (this->hp == 0)
		std::cout << "* SPROTCH *" << std::endl;
	else
		std::cout << "Now " << this->type << " have a "
			<< this->hp << " hit points" << std::endl;
}
