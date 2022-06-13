#include "Squad.hpp"

Squad::Squad(void)
	: army(nullptr), count(0)
{ }

Squad::~Squad()
{
	if (this->army != nullptr)
	{
		int		i = 0;

		while (i < this->count)
			delete this->army[i++];
		delete [] this->army;
	}
}

Squad::Squad(const Squad &squad)
{
	*this = squad;
}

Squad&	Squad::operator= (const Squad &squad)
{
	if (this->army != nullptr)
	{
		int		i = 0;

		while (i < this->count)
			delete this->army[i++];
	}
	this->count = squad.count;

	int		i = 0;
	this->army = new ISpaceMarine*[this->count];

	while (i < this->count)
	{
		this->army[i] = squad.army[i]->clone();
		i++;
	}
	return (*this);
}

int				Squad::getCount(void) const
{
	return (this->count);
}

ISpaceMarine*	Squad::getUnit(int n) const
{
	if (n < 0 || n >= this->count)
		return (nullptr);
	return (this->army[n]);
}

int				Squad::push(ISpaceMarine *marine)
{
	ISpaceMarine	**tmp = this->army;
	int				i = 0;

	this->army = new ISpaceMarine*[this->count + 1];
	while (i < this->count)
	{
		this->army[i] = tmp[i];
		i++;
	}
	this->army[i] = marine;
	this->count++;
	if (tmp != nullptr)
		delete [] tmp;
	return (this->count);
}
