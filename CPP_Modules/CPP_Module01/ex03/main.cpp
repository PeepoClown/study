#include "Zombie.hpp"
#include "ZombieHorde.hpp"
#include <iostream>

int		main(void)
{
	int	n;
	std::cout << "type quantity : ";
	std::cin >> n;
	if (n <= 0)
		std::cout << "invalid n" << std::endl;
	else
		ZombieHorde horde(n);
	return (0);
}
