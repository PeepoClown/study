#include "ISpaceMarine.hpp"
#include "AssaultTerminator.hpp"
#include "TacticalMarine.hpp"
#include "ISquad.hpp"
#include "Squad.hpp"
#include <iostream>

int		main(void)
{
	ISpaceMarine* bob = new TacticalMarine;
	ISpaceMarine* jim = new AssaultTerminator;
	ISquad* vlc = new Squad;

	vlc->push(bob);
	vlc->push(jim);
	for (int i = 0; i < vlc->getCount(); ++i)
	{
		ISpaceMarine* cur = vlc->getUnit(i);
		cur->battleCry();
		cur->rangedAttack();
		cur->meleeAttack();
	}

	std::cout << "------------------------------------------------------------------------------" << std::endl;

	Squad zergs;
	for (int i = 0; i < 5; i++)
	{
		if (i % 2 == 1)
			zergs.push(new TacticalMarine);
		else
			zergs.push(new AssaultTerminator);
	}
	Squad _zergs(zergs);
	_zergs.push(new TacticalMarine);
	for (int i = 0; i < _zergs.getCount(); ++i)
	{
		ISpaceMarine* cur = _zergs.getUnit(i);
		cur->battleCry();
		cur->rangedAttack();
		cur->meleeAttack();
	}

	delete vlc;

	return (0);
}
