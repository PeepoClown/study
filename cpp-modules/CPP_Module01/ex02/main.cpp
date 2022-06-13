#include "Zombie.hpp"
#include "ZombieEvent.hpp"
#include <unistd.h>

int		main(void)
{
	ZombieEvent zEvent;
	Zombie *zombie = zEvent.newZombie("Lexa");

	zombie->announce();
	delete zombie;
	zEvent.setZombieType("Witch");
	zombie = zEvent.newZombie("Anna-Maria");
	zombie->announce();
	delete zombie;
	zEvent.setZombieType("Jockey");
	for (int i = 0; i < 3; i++)
	{
		zEvent.randomChump();
		sleep(1);
	}
	return (0);
}
