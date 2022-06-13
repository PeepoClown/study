#ifndef SUPERTRAP_HPP
#define SUPERTRAP_HPP

#include "FragTrap.hpp"
#include "NinjaTrap.hpp"
#include <string>

class	SuperTrap : public FragTrap, public NinjaTrap
{
	public :
		SuperTrap(void);
		~SuperTrap();
		explicit SuperTrap(const std::string &name);
		SuperTrap(const SuperTrap &superTrap);

		SuperTrap&	operator= (const SuperTrap &superTrap);
};

#endif
