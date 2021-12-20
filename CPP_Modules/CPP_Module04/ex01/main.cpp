#include "AWeapon.hpp"
#include "PlasmaRifle.hpp"
#include "PowerFist.hpp"
#include "Enemy.hpp"
#include "SuperMutant.hpp"
#include "RadScorpion.hpp"
#include "Character.hpp"
#include <iostream>

int		main(void)
{
	Character* me = new Character("me");
	std::cout << *me;

	Enemy* b = new RadScorpion();
	AWeapon* pr = new PlasmaRifle();
	AWeapon* pf = new PowerFist();

	me->equip(pr);
	std::cout << *me;
	me->equip(pf);
	me->attack(b);
	std::cout << *me;
	me->equip(pr);
	std::cout << *me;
	me->attack(b);
	std::cout << *me;
	me->attack(b);
	std::cout << *me;

	std::cout << "===============================================================" << std::endl;

	Character* madMax = new Character("Mad Max");
	std::cout << *madMax;

	delete b;
	b = new SuperMutant();
	madMax->equip(pr);
	std::cout << *madMax;
	madMax->attack(b);
	madMax->equip(pf);
	std::cout << *madMax;
	madMax->attack(b);
	madMax->attack(b);
	std::cout << *madMax;
	madMax->attack(b);
	std::cout << *madMax;

	madMax->recoverAP();
	madMax->equip(pr);
	std::cout << *madMax;
	madMax->attack(b);
	madMax->attack(b);

	delete b;
	delete pf;
	delete pr;
	delete me;
	return (0);
}
