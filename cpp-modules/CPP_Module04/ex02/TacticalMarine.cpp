#include "TacticalMarine.hpp"

TacticalMarine::TacticalMarine(void)
{
	std::cout << "Tactical Marine ready for battle!" << std::endl;
}

TacticalMarine::~TacticalMarine()
{
	std::cout << "Aaargh..." << std::endl;
}

TacticalMarine::TacticalMarine(const TacticalMarine &tacticalMarine)
{
	std::cout << "Tactical Marine ready for battle!" << std::endl;
	*this = tacticalMarine;
}

TacticalMarine&	TacticalMarine::operator= (const TacticalMarine &tacticalMarine)
{
	static_cast<void>(tacticalMarine);
	return (*this);
}

void			TacticalMarine::battleCry(void) const
{
	std::cout << "For the holy PLOT!" << std::endl;
}

void			TacticalMarine::rangedAttack(void) const
{
	std::cout << "* attacks with a bolter *" << std::endl;
}

void			TacticalMarine::meleeAttack(void) const
{
	std::cout << "* attacks with a chainsword *" << std::endl;
}

ISpaceMarine*	TacticalMarine::clone(void) const
{
	return (new TacticalMarine(*this));
}
