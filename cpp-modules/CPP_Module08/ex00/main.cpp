#include "easyfind.hpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <random>

int		main(void)
{
	std::vector<int> vec(100);

	std::default_random_engine generator;
	generator.seed(std::time(nullptr));
	std::uniform_int_distribution<int> distribution(-100, 100);
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
		*it = distribution(generator);

	std::cout << "Vector contains : " << std::endl;
	for (std::size_t i = 0; i < vec.size(); i++)
	{
		std::cout << std::setw(5) << vec[i];
		if ((i + 1) % 10 == 0)
			std::cout << std::endl;
		else
			std::cout << " ";
	}

	for (int i = 0; i < 5; i++)
		try
		{
			int		value;
			std::cout << "search value : ";
			std::cin >> value;
			int foundValue = easyfind(vec, value);
			std::cout << "found " << foundValue << " in container" << std::endl;
		}
		catch(const std::exception &exception)
		{
			std::cerr << exception.what() << std::endl;
		}

	return (0);
}
