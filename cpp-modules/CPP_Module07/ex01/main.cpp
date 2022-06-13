#include "iter.hpp"
#include "Awesome.hpp"
#include <iostream>
#include <string>

int		main(void)
{
	int			integerArray[] = { 11, -4, 6, 2, 8, 1, 0, -2, -4, 18 };
	std::size_t	arrayLen = sizeof(integerArray) / sizeof(int);
	::iter(integerArray, arrayLen, print);
	std::cout << std::endl;

	::iter(integerArray, arrayLen, cmp);
	std::cout << "sorted : ";
	::iter(integerArray, arrayLen, print);
	std::cout << std::endl;

	double		doubleArray[] = { 100.42, -4.5, 6.12, 2., .8, 1.1, 0, -2.6, -452.3, 18.12 };
	arrayLen = sizeof(doubleArray) / sizeof(double);
	::iter(doubleArray, arrayLen, print);
	std::cout << std::endl;

	::iter(doubleArray, arrayLen, cmp);
	std::cout << "sorted : ";
	::iter(doubleArray, arrayLen, print);
	std::cout << std::endl;

	std::string	stringArray[] = { "asd", "zxc", "qwe", "jijijij" };
	arrayLen = 4;
	::iter(stringArray, arrayLen, print);
	std::cout << std::endl;

	::iter(stringArray, arrayLen, cmp);
	std::cout << "sorted : ";
	::iter(stringArray, arrayLen, print);
	std::cout << std::endl;

	int tab[] = { 0, 1, 2, 3, 4 };
	Awesome tab2[5];
	
	iter(tab, 5, print);
	std::cout << std::endl;
	iter(tab2, 5, print);
	std::cout << std::endl;

	return (0);
}
