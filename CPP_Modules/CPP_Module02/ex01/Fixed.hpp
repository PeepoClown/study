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
		explicit Fixed(const int int_value);
		explicit Fixed(const float float_value);
		Fixed(const Fixed &fixed);

		Fixed&	operator= (const Fixed &fixed);

		int		getRawBits(void) const;
		void	setRawBits(const int raw);
		int		toInt(void) const;
		float	toFloat(void) const;
};

std::ostream&	operator<< (std::ostream &out, const Fixed &fixed);
int				spasibo_chto_zapretili_pow(int base, int exponent);

#endif
