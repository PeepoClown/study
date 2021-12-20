#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class	ClapTrap
{
	protected :
		size_t		hp;
		size_t		hpMax;
		size_t		ep;
		size_t		epMax;
		size_t		level;
		std::string	name;
		size_t		meleeDmg;
		size_t		rangeDmg;
		size_t		armorRed;
		std::string	type;
	public :
		ClapTrap(void);
		~ClapTrap();
		ClapTrap(const ClapTrap &clapTrap);

		ClapTrap&	operator= (const ClapTrap &clapTrap);

		std::string	getName(void) const;
		std::string	getType(void) const;

		size_t	rangedAttack(const std::string &target);
		size_t	meleeAttack(const std::string &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};

#endif
