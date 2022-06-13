#ifndef COMPLEX_HPP
#define COMPLEX_HPP

#include <iostream>
#include <cmath>

class	Complex
{
	private :
		double	real,
				imaginary;
	public :
		Complex(void);
		~Complex();
		explicit Complex(const double &real, const double &imaginary);
		Complex(const Complex &complex);

		Complex&	operator= (const Complex &complex);
		bool		operator< (const Complex &complex);
		bool		operator> (const Complex &complex);

		double	getReal(void) const;
		double	getImaginary(void) const;
};

std::ostream&	operator<< (std::ostream &out, const Complex &complex);

#endif
