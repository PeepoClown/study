#ifndef ZOMBIEEVENT_HPP
#define ZOMBIEEVENT_HPP

#include "Zombie.hpp"
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

class ZombieEvent
{
	private :
		std::string zType;
	public :
		ZombieEvent(void);
		ZombieEvent(const std::string &type);

		void	setZombieType(const std::string &type);
		Zombie*	newZombie(const std::string &name);
		void	randomChump(void);
};


#endif
