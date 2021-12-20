#include "FragTrap.hpp"
#include <unistd.h>

int		main(void)
{
	FragTrap ft1("Eva00");
	FragTrap ft2("C-3PO");
	FragTrap ft3("Bumblebee");

	ft2.takeDamage(ft1.meleeAttack(ft2.getName()));
	ft2.beRepaired(20);
	ft1.beRepaired(20);
	ft3.takeDamage(ft2.vaulthunter_dot_exe(ft3.getName()));
	sleep(1);
	ft3.takeDamage(ft3.vaulthunter_dot_exe(ft3.getName()));
	return (0);
}
