#include "AssaultTerminator.hpp"

AssaultTerminator::AssaultTerminator(void)
{
	std::cout << "* teleports from space *" << std::endl;
}

AssaultTerminator::~AssaultTerminator()
{
	std::cout << "I’ll be back..." << std::endl;
}

AssaultTerminator::AssaultTerminator(const AssaultTerminator &assaultTerminator)
{
	std::cout << "* teleports from space *" << std::endl;
	*this = assaultTerminator;
}

AssaultTerminator&	AssaultTerminator::operator= (const AssaultTerminator &assaultTerminator)
{
	static_cast<void>(assaultTerminator);
	return (*this);
}

void				AssaultTerminator::battleCry(void) const
{
	std::cout << "This code is unclean. PURIFY IT!" << std::endl;
}

void				AssaultTerminator::rangedAttack(void) const
{
	std::cout << "* does nothing *" << std::endl;
}

void				AssaultTerminator::meleeAttack(void) const
{
	std::cout << "* attacks with chainfists *" << std::endl;
}

ISpaceMarine*		AssaultTerminator::clone(void) const
{
	return (new AssaultTerminator(*this));
}
