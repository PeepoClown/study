#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "AWeapon.hpp"
#include "Enemy.hpp"
#include <string>
#include <iostream>

class	Character
{
	private :
		std::string	name;
		int			ap;
		AWeapon		*weapon;
	public :
		Character(void);
		~Character();
		explicit Character(const std::string &name);
		Character(const Character &character);

		Character&	operator= (const Character &character);

		std::string	getName(void) const;
		int			getAP(void) const;
		AWeapon*	getWeapon(void) const;

		void		recoverAP(void);
		void		equip(AWeapon *weapon);
		void		attack(Enemy *enemy);
};

std::ostream&	operator<< (std::ostream &out, const Character &character);

#endif
