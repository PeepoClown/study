#ifndef SQUAD_HPP
#define SQUAD_HPP

#include "ISquad.hpp"
#include "ISpaceMarine.hpp"
#include <iostream>

class	Squad : public ISquad
{
	private :
		ISpaceMarine	**army;
		int				count;
	public :
		Squad(void);
		virtual ~Squad();
		Squad(const Squad &squad);

		Squad&	operator= (const Squad &squad);

		int				getCount(void) const;
		ISpaceMarine*	getUnit(int n) const;
		int				push(ISpaceMarine *marine);
};

#endif
