#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

class	FragTrap
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
		FragTrap(void);
		~FragTrap();
		explicit FragTrap(const std::string &name);
		FragTrap(const FragTrap &fragTrap);

		FragTrap&	operator= (const FragTrap &fragTrap);

		std::string	getName(void) const;

		size_t	rangedAttack(const std::string &target);
		size_t	meleeAttack(const std::string &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		size_t	vaulthunter_dot_exe(const std::string &target);
};

#endif
