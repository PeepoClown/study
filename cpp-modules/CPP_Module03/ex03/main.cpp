#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"

int		main(void)
{
	FragTrap ft1("Eva00");
	ScavTrap st1("Van");
	NinjaTrap nt1("Samuray");

	ft1.takeDamage(st1.rangedAttack(ft1.getName()));
	st1.takeDamage(nt1.meleeAttack(st1.getName()));

	ft1.takeDamage(nt1.ninjaShoebox(ft1));
	st1.takeDamage(nt1.ninjaShoebox(st1));
	nt1.takeDamage(nt1.ninjaShoebox(nt1));
	return (0);
}
