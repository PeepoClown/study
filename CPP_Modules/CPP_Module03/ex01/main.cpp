#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <unistd.h>

int		main(void)
{
	FragTrap ft1("Eva00");
	FragTrap ft2("C-3PO");
	FragTrap ft3("Bumblebee");
	ScavTrap st1("Van");
	ScavTrap st2("Billie");

	ft2.takeDamage(ft1.meleeAttack(ft2.getName()));
	ft2.beRepaired(20);
	ft1.beRepaired(20);
	ft3.takeDamage(ft2.vaulthunter_dot_exe(ft3.getName()));
	sleep(1);
	ft3.takeDamage(ft3.vaulthunter_dot_exe(ft3.getName()));

	st2.takeDamage(st1.meleeAttack(st2.getName()));
	st1.challengeNewcomer(st2.getName());
	sleep(1);
	st2.challengeNewcomer(st1.getName());
	return (0);
}
