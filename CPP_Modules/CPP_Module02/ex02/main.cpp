#include "Fixed.hpp"
#include <iostream>

int		main(void)
{
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));

	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;

	a++;
	std::cout << "after a++ : " << a << std::endl;
	std::cout << "++a : " << ++a << std::endl;

	a = Fixed(7.55f);
	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;

	std::cout << "a > b : " << std::boolalpha << (a > b) << std::endl;
	std::cout << "a < b : " << std::boolalpha << (a < b) << std::endl;
	std::cout << "a >= b : " << std::boolalpha << (a >= b) << std::endl;
	std::cout << "a <= b : " << std::boolalpha << (a <= b) << std::endl;
	std::cout << "a == b : " << std::boolalpha << (a == b) << std::endl;
	std::cout << "a != b : " << std::boolalpha << (a != b) << std::endl;

	std::cout << "a + b : " << (a + b) << std::endl;
	std::cout << "a - b : " << (a - b) << std::endl;
	std::cout << "a * b : " << (a * b) << std::endl;
	std::cout << "a / b : " << (a / b) << std::endl;

	std::cout << "max : " << max(a, b) << std::endl;
	std::cout << "min : " << min(a, b) << std::endl;
	return (0);
}
