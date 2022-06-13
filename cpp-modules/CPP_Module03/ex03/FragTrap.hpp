#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

class	FragTrap : public ClapTrap
{
	public :
		FragTrap(void);
		~FragTrap();
		explicit FragTrap(const std::string &name);
		FragTrap(const FragTrap &fragTrap);

		FragTrap&	operator= (const FragTrap &fragTrap);

		size_t	vaulthunter_dot_exe(const std::string &target);
};

#endif
