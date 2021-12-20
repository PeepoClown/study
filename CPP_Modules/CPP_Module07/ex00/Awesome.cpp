#include "Awesome.hpp"

Awesome::Awesome(void)
	: _n (0)
{ }

Awesome::~Awesome()
{ }

Awesome::Awesome(int n)
	: _n(n)
{ }

Awesome::Awesome(const Awesome &awesome)
{
	*this = awesome;
}

Awesome&	Awesome::operator= (const Awesome &awesome)
{
	this->_n = awesome._n;
	return (*this);
}

bool		Awesome::operator== (const Awesome &rhs)
{
	return (this->_n == rhs._n);
}

bool		Awesome::operator!= (const Awesome &rhs)
{
	return (this->_n != rhs._n);
}

bool		Awesome::operator> (const Awesome &rhs)
{
	return (this->_n > rhs._n);
}

bool		Awesome::operator< (const Awesome &rhs)
{
	return (this->_n < rhs._n);
}

bool		Awesome::operator>= (const Awesome &rhs)
{
	return (this->_n >= rhs._n);
}

bool		Awesome::operator<= (const Awesome &rhs)
{
	return (this->_n <= rhs._n);
}

int	Awesome::getN(void) const
{
	return (this->_n);
}

std::ostream&	operator<< (std::ostream &out, const Awesome &awesome)
{
	out << awesome.getN();
	return (out);
}
