#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

class	ScavTrap : public ClapTrap
{
	public :
		ScavTrap(void);
		~ScavTrap();
		explicit ScavTrap(const std::string &name);
		ScavTrap(const ScavTrap &scavTrap);

		ScavTrap&	operator= (const ScavTrap &scavTrap);

		void	challengeNewcomer(const std::string &target);
};

#endif
