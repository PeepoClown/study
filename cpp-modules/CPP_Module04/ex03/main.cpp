#include "AMateria.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "FireBall.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include <iostream>

int		main(void)
{
	IMateriaSource *src = new MateriaSource();

	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter *me = new Character("me");

	AMateria *tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter *bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete src;
	delete me;

	std::cout << "------------------------------------------------------------------------------" << std::endl;

	ICharacter *character = new Character("Evil Arthas");
	Character character2("Jaina Proudmoore");

	IMateriaSource *srcs = new MateriaSource();

	srcs->learnMateria(new Ice());
	srcs->learnMateria(new Cure());
	srcs->learnMateria(new FireBall());

	AMateria *temp;
	temp = srcs->createMateria("ice");
	character2.equip(temp);
	temp = srcs->createMateria("cure");
	character2.equip(temp);
	temp = srcs->createMateria("fire ball");
	character2.equip(temp);

	Character character3(character2);

	std::cout << character3.getName() << " start attack" << std::endl;
	character3.use(0, *character);
	character3.use(1, *character);
	character3.use(2, *character);

	delete character;
	delete srcs;

	return (0);
}