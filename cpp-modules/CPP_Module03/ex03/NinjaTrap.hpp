#ifndef NINJATRAP_HPP
#define NINJATRAP_HPP

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>
#include <string>

class	NinjaTrap : public ClapTrap
{
	public :
		NinjaTrap(void);
		~NinjaTrap();
		explicit NinjaTrap(const std::string &name);
		NinjaTrap(const NinjaTrap &ninjaTrap);

		NinjaTrap&	operator= (const NinjaTrap &ninjaTrap);

		size_t	ninjaShoebox(const FragTrap &fragTrap);
		size_t	ninjaShoebox(const ScavTrap &scavTrap);
		size_t	ninjaShoebox(const NinjaTrap &ninjaTrap);
};

#endif
