#include "FireBall.hpp"

FireBall::FireBall(void)
	: AMateria("fire ball")
{ }

FireBall::~FireBall()
{ }

FireBall::FireBall(const FireBall &fireBall)
{
	*this = fireBall;
}

FireBall&	FireBall::operator= (const FireBall &fireBall)
{
	this->xp = fireBall.xp;
	this->type = fireBall.type;
	return (*this);
}

AMateria*	FireBall::clone(void) const
{
	return (new FireBall(*this));
}

void		FireBall::use(ICharacter &target)
{
	AMateria::use(target);
	std::cout << "* shoots an fire bolt at " << target.getName() << " *" << std::endl;
}
