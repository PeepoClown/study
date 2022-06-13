#include "Pony.hpp"
#include <iostream>

void	ponyOnTheHeap(void)
{
	Pony *pony = new Pony("Bucefal na heap'e", 40, 20);

	std::cout << "Pony on the heap" << std::endl;
	pony->doSmth();
	delete pony;
}

void	ponyOnTheStack(void)
{
	Pony pony("Bucefal na stek'e", 50, 21);

	std::cout << "Pony on the stack" << std::endl;
	pony.doSmth();
}

int		main(void)
{
	ponyOnTheHeap();
	std::cout << std::endl << std::endl << std::endl;
	ponyOnTheStack();
	return (0);
}
