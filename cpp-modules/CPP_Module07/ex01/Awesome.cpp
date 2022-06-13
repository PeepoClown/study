#include "Awesome.hpp"

Awesome::Awesome(void)
	: _n (42)
{ }

Awesome::~Awesome()
{ }

Awesome::Awesome(const Awesome &awesome)
{
	*this = awesome;
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
