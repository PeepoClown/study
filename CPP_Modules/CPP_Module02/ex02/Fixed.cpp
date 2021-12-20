#include "Fixed.hpp"

Fixed::Fixed(void)
	: rawBits(0)
{ }

Fixed::~Fixed()
{ }

Fixed::Fixed(int int_value)
{
	this->rawBits = int_value << Fixed::shift;
}

Fixed::Fixed(float float_value)
{
	this->rawBits = roundf(float_value *
		spasibo_chto_zapretili_pow(2, Fixed::shift));
}

Fixed::Fixed(const Fixed &fixed)
{
	*this = fixed;
}

Fixed&	Fixed::operator= (const Fixed &fixed)
{
	this->rawBits = fixed.getRawBits();
	return (*this);
}

bool	Fixed::operator< (const Fixed &fixed) const
{
	return (this->toFloat() < fixed.toFloat());
}

bool	Fixed::operator> (const Fixed &fixed) const
{
	return (this->toFloat() > fixed.toFloat());
}

bool	Fixed::operator<= (const Fixed &fixed) const
{
	return (this->toFloat() <= fixed.toFloat());
}

bool	Fixed::operator>= (const Fixed &fixed) const
{
	return (this->toFloat() >= fixed.toFloat());
}

bool	Fixed::operator== (const Fixed &fixed) const
{
	return (this->toFloat() == fixed.toFloat());
}

bool	Fixed::operator!= (const Fixed &fixed) const
{
	return (this->toFloat() != fixed.toFloat());
}

Fixed	Fixed::operator+ (const Fixed &fixed) const
{
	return (Fixed(this->toFloat() + fixed.toFloat()));
}

Fixed	Fixed::operator- (const Fixed &fixed) const
{
	return (Fixed(this->toFloat() - fixed.toFloat()));
}

Fixed	Fixed::operator* (const Fixed &fixed) const
{
	return (Fixed(this->toFloat() * fixed.toFloat()));
}

Fixed	Fixed::operator/ (const Fixed &fixed) const
{
	return (Fixed(this->toFloat() / fixed.toFloat()));
}

Fixed&	Fixed::operator++()
{
	this->rawBits++;
	return (*this);
}

Fixed&	Fixed::operator--()
{
	this->rawBits--;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed tmp(this->getRawBits());
	this->rawBits++;
	return (tmp);
}

Fixed	Fixed::operator--(int)
{
	Fixed tmp(this->getRawBits());
	this->rawBits--;
	return (tmp);
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

Fixed&	min(Fixed &fixed1, Fixed &fixed2)
{
	return (fixed1.toFloat() < fixed2.toFloat() ? fixed1 : fixed2);
}

const Fixed&	min(const Fixed &fixed1, const Fixed &fixed2)
{
	return (fixed1.toFloat() < fixed2.toFloat() ? fixed1 : fixed2);
}

Fixed&	max(Fixed &fixed1, Fixed &fixed2)
{
	return (fixed1.toFloat() > fixed2.toFloat() ? fixed1 : fixed2);
}

const Fixed&	max(const Fixed &fixed1, const Fixed &fixed2)
{
	return (fixed1.toFloat() > fixed2.toFloat() ? fixed1 : fixed2);
}
