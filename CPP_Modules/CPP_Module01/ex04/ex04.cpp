#include <iostream>
#include <string>

int		main(void)
{
	std::string	string("HI THIS IS BRAIN");
	std::string	*ptr = &string;
	std::string	&ref = string;

	std::cout << "By pointer : " << *ptr << std::endl;
	std::cout << "By reference : " << ref << std::endl;
	return (0);
}
