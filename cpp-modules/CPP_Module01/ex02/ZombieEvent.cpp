#include "ZombieEvent.hpp"

ZombieEvent::ZombieEvent(void)
	: zType("default")
{ }

ZombieEvent::ZombieEvent(const std::string &type)
	: zType(type)
{ }

void	ZombieEvent::setZombieType(const std::string &type)
{
	this->zType = type;
}

Zombie*	ZombieEvent::newZombie(const std::string &name)
{
	Zombie *zombie = new Zombie(name, this->zType);
	return (zombie);
}

void	ZombieEvent::randomChump(void)
{
	const std::string names[] = { "Arkasha", "Stepka", "Dim0n4eg",
		"Petya2004RUS", "P|bnR" };
	srand(time(NULL));

	Zombie *zombie = new Zombie(names[rand() % 5], this->zType);

	zombie->announce();
	delete zombie;
}
