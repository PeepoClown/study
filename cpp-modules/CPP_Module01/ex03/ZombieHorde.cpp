#include "ZombieHorde.hpp"

ZombieHorde::ZombieHorde(void)
	: zombies(NULL)
{ }

ZombieHorde::ZombieHorde(int n)
{
	const std::string names[] = { "Arkasha", "Stepka", "Dim0n4eg",
		"Petya2004RUS", "P|bnR" };
	const std::string types[] = { "Jockey", "Witch", "Boomer",
		"Smoker", "Hunter" };
	srand(time(NULL));

	this->zombies = new Zombie[n];
	for (int i = 0; i < n; i++)
	{
		this->zombies[i].setName(names[rand() % 5]);
		this->zombies[i].setType(types[rand() % 5]);
		this->zombies[i].announce();
		sleep(1);
	}
}

ZombieHorde::~ZombieHorde()
{
	delete[] this->zombies;
}
