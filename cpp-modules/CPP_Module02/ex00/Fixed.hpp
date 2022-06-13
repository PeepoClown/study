#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class	Fixed
{
	private :
		int					rawBits;
		static const int	shift = 8;
	public :
		Fixed(void);
		~Fixed();
		Fixed(const Fixed &fixed);

		Fixed&	operator= (const Fixed &fixed);

		int		getRawBits(void) const;
		void	setRawBits(const int raw);
};

#endif
