#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class	Fixed
{
	private :
		int					rawBits;
		static const int	shift = 8;
	public :
		Fixed(void);
		~Fixed();
		explicit Fixed(int int_value);
		explicit Fixed(float float_value);
		Fixed(const Fixed &fixed);

		Fixed&	operator= (const Fixed &fixed);
		bool	operator< (const Fixed &fixed) const;
		bool	operator> (const Fixed &fixed) const;
		bool	operator<= (const Fixed &fixed) const;
		bool	operator>= (const Fixed &fixed) const;
		bool	operator== (const Fixed &fixed) const;
		bool	operator!= (const Fixed &fixed) const;
		Fixed	operator+ (const Fixed &fixed) const;
		Fixed	operator- (const Fixed &fixed) const;
		Fixed	operator* (const Fixed &fixed) const;
		Fixed	operator/ (const Fixed &fixed) const;
		Fixed&	operator++();
		Fixed&	operator--();
		Fixed	operator++(int);
		Fixed	operator--(int);

		int		getRawBits(void) const;
		void	setRawBits(const int raw);
		int		toInt(void) const;
		float	toFloat(void) const;
};

std::ostream&	operator<< (std::ostream &out, const Fixed &fixed);
int				spasibo_chto_zapretili_pow(int base, int exponent);

Fixed&	min(Fixed &fixed1, Fixed &fixed2);
const Fixed&	min(const Fixed &fixed1, const Fixed &fixed2);
Fixed&	max(Fixed &fixed1, Fixed &fixed2);
const Fixed&	max(const Fixed &fixed1, const Fixed &fixed2);

#endif
