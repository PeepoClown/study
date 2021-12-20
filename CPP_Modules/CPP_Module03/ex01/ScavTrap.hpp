#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

class	ScavTrap
{
	private :
		size_t		hp;
		size_t		hpMax;
		size_t		ep;
		size_t		epMax;
		size_t		level;
		std::string	name;
		size_t		meleeDmg;
		size_t		rangeDmg;
		size_t		armorRed;
	public :
		ScavTrap(void);
		~ScavTrap();
		explicit ScavTrap(const std::string &name);
		ScavTrap(const ScavTrap &scavTrap);

		ScavTrap&	operator= (const ScavTrap &scavTrap);

		std::string	getName(void) const;

		size_t	rangedAttack(const std::string &target);
		size_t	meleeAttack(const std::string &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		void	challengeNewcomer(const std::string &target);
};

#endif
