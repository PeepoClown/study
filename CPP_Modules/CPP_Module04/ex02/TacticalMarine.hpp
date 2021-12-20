#ifndef TACTICALMARINE_HPP
#define TACTICALMARINE_HPP

#include "ISpaceMarine.hpp"
#include <iostream>

class	TacticalMarine : public ISpaceMarine
{
	public :
		TacticalMarine(void);
		virtual ~TacticalMarine();
		TacticalMarine(const TacticalMarine &tacticalMatine);

		TacticalMarine&	operator= (const TacticalMarine &tacticalMatine);

		void			battleCry(void) const;
		void			rangedAttack(void) const;
		void			meleeAttack(void) const;
		ISpaceMarine*	clone(void) const;
};

#endif
