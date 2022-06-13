#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
	private :
		std::string name,
					type;
	public :
		Zombie(void);
		Zombie(const std::string &name, const std::string &type);

		void	announce(void);
};

#endif
