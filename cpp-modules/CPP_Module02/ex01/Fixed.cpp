#include "Fixed.hpp"

Fixed::Fixed(void)
	: rawBits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const int int_value)
{
	std::cout << "Int constructor called" << std::endl;
	this->rawBits = int_value << Fixed::shift;
}

Fixed::Fixed(const float float_value)
{
	std::cout << "Float constructor called" << std::endl;
	this->rawBits = roundf(float_value *
		spasibo_chto_zapretili_pow(2, Fixed::shift));
}

Fixed::Fixed(const Fixed &fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed&	Fixed::operator= (const Fixed &fixed)
{
	std::cout << "Assignation operator called" << std::endl;
	this->rawBits = fixed.getRawBits();
	return (*this);
}

int		Fixed::getRawBits(void) const
{
	return (this->rawBits);
}

void	Fixed::setRawBits(const int raw)
{
	this->rawBits = raw;
}

int		Fixed::toInt(void) const
{
	return (this->rawBits >> Fixed::shift);
}

float	Fixed::toFloat(void) const
{
	return (static_cast<float>(this->rawBits) /
		spasibo_chto_zapretili_pow(2, Fixed::shift));
}

std::ostream&	operator<< (std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}

int				spasibo_chto_zapretili_pow(int base, int exponent)
{
	int		result = 1;

	for (int i = exponent; i > 0; i--)
		result *= base;
	return (result);
}
