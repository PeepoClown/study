#include "whatever.hpp"
#include "Complex.hpp"
#include "Awesome.hpp"
#include <iostream>
#include <string>

int		main(void)
{
	int a = 2;
	int b = 3;
	::swap(a, b);
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
	std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
	std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;

	double pi = 3.14159;
	double e = 2.71828;
	::swap(pi, e);
	std::cout << "pi = " << pi << ", e = " << e << std::endl;
	std::cout << "min( pi, e ) = " << ::min(pi, e) << std::endl;
	std::cout << "max( pi, e ) = " << ::max(pi, e) << std::endl;

	Complex c1(2, -1);
	Complex c2(2, 0.67);
	::swap(c1, c2);
	std::cout << "c1 = " << c1 << ", c2 = " << c2 << std::endl;
	std::cout << "min( c1, c2 ) = " << ::min(c1, c2) << std::endl;
	std::cout << "max( c1, c2 ) = " << ::max(c1, c2) << std::endl;

	Awesome a1(45);
	Awesome a2(54);
	::swap(a1, a2);
	std::cout << "a1 = " << a1 << ", a2 = " << a2 << std::endl;
	std::cout << "min( a1, a2 ) = " << ::min(a1, a2) << std::endl;
	std::cout << "max( a1, a2 ) = " << ::max(a1, a2) << std::endl;

	return (0);
}
