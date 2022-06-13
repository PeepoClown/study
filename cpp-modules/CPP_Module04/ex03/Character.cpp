#include "Character.hpp"

#include <iostream>

Character::Character(void)
	: name("")
{
	for (int i = 0; i < 4; i++)
		this->inventory[i] = nullptr;
}

Character::~Character()
{
	int		i = 0;
	while (this->inventory[i] != nullptr && i < 4)
		delete inventory[i++];
}

Character::Character(const std::string &name)
	: name(name)
{
	for (int i = 0; i < 4; i++)
		this->inventory[i] = nullptr;
}

Character::Character(const Character &character)
{
	*this = character;
}

Character&	Character::operator= (const Character &character)
{
	int			i = 0;

	this->name = character.name;
	for (i = 0; i < 4; i++)
		if (character.inventory[i] != nullptr)
			this->inventory[i] = character.inventory[i]->clone();
		else
			this->inventory[i] = nullptr;
	return (*this);
}

const std::string&	Character::getName(void) const
{
	return (this->name);
}

void				Character::equip(AMateria *materia)
{
	int		i = 0;
	while (this->inventory[i] != nullptr)
		i++;
	if (i < 4)
		this->inventory[i] = materia;
}

void				Character::unequip(int idx)
{
	if ((idx < 0 || idx > 3) || this->inventory[idx] == nullptr)
		return ;
	this->inventory[idx] = nullptr;
	for (int i = idx; i < 3; i++)
		this->inventory[i] = this->inventory[i + 1];
}

void				Character::use(int idx, ICharacter &target)
{
	if ((idx < 0 || idx > 3) || this->inventory[idx] == nullptr)
		return ;
	this->inventory[idx]->use(target);
}
