#ifndef FIREBALL_HPP
#define FIREBALL_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>
#include <string>

class	FireBall : public AMateria
{
	public :
		FireBall(void);
		virtual ~FireBall();
		FireBall(const FireBall &fireBall);

		FireBall&	operator= (const FireBall &fireBall);

		AMateria*	clone(void) const;
		void		use(ICharacter &target);
};

#endif
