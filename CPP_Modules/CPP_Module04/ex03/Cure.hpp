#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>
#include <string>

class	Cure : public AMateria
{
	public :
		Cure(void);
		virtual ~Cure();
		Cure(const Cure &cure);

		Cure&	operator= (const Cure &cure);

		AMateria*	clone(void) const;
		void		use(ICharacter &target);
};

#endif
