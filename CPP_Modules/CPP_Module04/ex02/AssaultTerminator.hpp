#ifndef ASSAULTTERMINATOR_HPP
#define ASSAULTTERMINATOR_HPP

#include "ISpaceMarine.hpp"
#include <iostream>

class	AssaultTerminator : public ISpaceMarine
{
	public :
		AssaultTerminator(void);
		virtual ~AssaultTerminator();
		AssaultTerminator(const AssaultTerminator &assaultTerminator);

		AssaultTerminator&	operator= (const AssaultTerminator &assaultTerminator);

		void				battleCry(void) const;
		void				rangedAttack(void) const;
		void				meleeAttack(void) const;
		ISpaceMarine*		clone(void) const;
};

#endif
