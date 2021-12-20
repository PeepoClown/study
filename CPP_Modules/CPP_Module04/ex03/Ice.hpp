#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>
#include <string>

class	Ice : public AMateria
{
	public :
		Ice(void);
		virtual ~Ice();
		Ice(const Ice &ice);

		Ice&	operator= (const Ice &ice);

		AMateria*	clone(void) const;
		void		use(ICharacter &target);
};

#endif
