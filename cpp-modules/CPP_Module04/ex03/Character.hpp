#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"
#include <string>

class	Character : public ICharacter
{
	private :
		AMateria*	inventory[4];
		std::string	name;
	public :
		Character(void);
		virtual ~Character();
		Character(const std::string &name);
		Character(const Character &character);

		Character&	operator= (const Character &character);

		const std::string&	getName(void) const;
		void				equip(AMateria *materia);
		void				unequip(int idx);
		void				use(int idx, ICharacter &target);
};

#endif
