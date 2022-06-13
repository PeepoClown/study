#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
	: materia(nullptr), count(0)
{ }

MateriaSource::~MateriaSource()
{
	if (this->materia != nullptr)
	{
		for (int i = 0; i < this->count; i++)
			delete this->materia[i];
		delete this->materia;
	}
}

MateriaSource::MateriaSource(const MateriaSource &materiaSource)
{
	*this = materiaSource;
}

MateriaSource&	MateriaSource::operator= (const MateriaSource &materiaSource)
{
	if (this->materia != nullptr)
	{
		for (int i = 0; i < this->count; i++)
			delete this->materia[i];
		delete this->materia;
	}

	this->count = materiaSource.count;
	this->materia = new AMateria*[this->count];
	for (int i = 0; i < this->count; i++)
		this->materia[i] = materiaSource.materia[i]->clone();
	return (*this);
}

void		MateriaSource::learnMateria(AMateria *materia)
{
	if (this->materia == nullptr)
	{
		this->materia = new AMateria*;
		this->materia[0] = materia->clone();
	}
	else
	{
		AMateria	**tmp = this->materia;
		this->materia = new AMateria*[this->count + 1];

		int i = 0;
		for (i = 0; i < this->count; i++)
			this->materia[i] = tmp[i]->clone();
		this->materia[i] = materia->clone();
		for (int i = 0; i < this->count; i++)
			delete tmp[i];
		delete tmp;
	}
	this->count++;
}

AMateria*	MateriaSource::createMateria(const std::string &type)
{
	if (this->materia == nullptr)
		return (nullptr);
	for (int i = 0; i < this->count; i++)
	{
		if (this->materia[i]->getType() == type)
			return (this->materia[i]->clone());
	}
	return (nullptr);
}
