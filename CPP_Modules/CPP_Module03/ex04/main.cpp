#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"
#include "SuperTrap.hpp"

int		main(void)
{
	FragTrap ft1("Eva00");
	ScavTrap st1("Van");
	NinjaTrap nt1("Samuray");
	SuperTrap sut1("RK800 Connor");

	ft1.takeDamage(st1.rangedAttack(ft1.getName()));
	st1.takeDamage(nt1.meleeAttack(st1.getName()));

	ft1.takeDamage(nt1.ninjaShoebox(ft1));
	st1.takeDamage(nt1.ninjaShoebox(st1));
	nt1.takeDamage(nt1.ninjaShoebox(nt1));
	
	sut1.takeDamage(st1.meleeAttack(sut1.getName()));
	sut1.beRepaired(5);
	ft1.takeDamage(sut1.vaulthunter_dot_exe(ft1.getName()));
	nt1.takeDamage(sut1.ninjaShoebox(nt1));
	return (0);
}
