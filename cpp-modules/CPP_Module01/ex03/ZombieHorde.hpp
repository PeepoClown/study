#ifndef ZOMBIEHORDE_HPP
#define ZOMBIEHORDE_HPP

#include "Zombie.hpp"
#include <ctime>
#include <cstdlib>
#include <unistd.h>

class	ZombieHorde
{
	private :
		Zombie		*zombies;
	public :
		ZombieHorde(void);
		ZombieHorde(int n);
		~ZombieHorde();
};

#endif
