#include "Translator.hpp"
#include <iostream>

int		main(int argc, char **argv)
{
	if (argc != 2)
		std::cout << "Invalid count of params" << std::endl;
	else
	{
		Translator t(argv[1]);

		std::cout << "literal type : " << t.getType() << std::endl;
		t.print_char();
		t.print_int();
		std::cout.setf(std::ios::fixed);
		std::cout.precision(1);
		t.print_float();
		t.print_double();
	}
	return (0);
}
