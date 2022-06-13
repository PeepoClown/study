#include "Complex.hpp"

Complex::Complex(void)
	: real(0.0), imaginary(0.0)
{ }

Complex::~Complex()
{ }

Complex::Complex(const double &real, const double &imaginary)
	: real(real), imaginary(imaginary)
{ }

Complex::Complex(const Complex &complex)
{
	*this = complex;
}

Complex&	Complex::operator= (const Complex &complex)
{
	this->real = complex.real;
	this->imaginary = complex.imaginary;
	return (*this);
}

bool		Complex::operator< (const Complex &complex)
{
	double mod1 = sqrt(pow(this->real, 2) + pow(this->imaginary, 2));
	double mod2 = sqrt(pow(complex.real, 2) + pow(complex.imaginary, 2));

	return (mod1 < mod2);
}

bool		Complex::operator> (const Complex &complex)
{
	double mod1 = sqrt(pow(this->real, 2) + pow(this->imaginary, 2));
	double mod2 = sqrt(pow(complex.real, 2) + pow(complex.imaginary, 2));

	return (mod1 > mod2);
}

double	Complex::getReal(void) const
{
	return (this->real);
}

double	Complex::getImaginary(void) const
{
	return (this->imaginary);
}

std::ostream&	operator<< (std::ostream &out, const Complex &complex)
{
	out << "(Re : " << complex.getReal() << ", Im : " << complex.getImaginary() << ")";
	return (out);
}
