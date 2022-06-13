#include "Zombie.hpp"

Zombie::Zombie(void)
	: name(""), type("")
{ }

Zombie::Zombie(const std::string &name, const std::string &type)
	: name(name), type(type)
{ }

void	Zombie::announce(void)
{
	std::cout << "name : " << this->name << " | type : " << this->type
		<< " | Braiiiiiiinnnssss..." << std::endl;
}
