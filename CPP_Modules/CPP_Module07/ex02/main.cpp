#include "Array.tpp"
#include <iostream>
#include <random>

void	fillIntArray(Array<int> *array)
{
	std::default_random_engine generator;
	generator.seed(std::time(nullptr));
	std::uniform_int_distribution<int> distribution(-100, 100);
	for (std::size_t i = 0; i < (*array).size(); i++)
		(*array)[i] = distribution(generator);
}

void	fillDoubleArray(Array<double> *array)
{
	std::default_random_engine generator;
	generator.seed(std::time(nullptr));
	std::uniform_int_distribution<double> distribution(-100.0, 100.0);
	for (std::size_t i = 0; i < (*array).size(); i++)
		(*array)[i] = distribution(generator) + distribution(generator) / 100.0;
}

int		main(void)
{
	Array<int> arrayInt(10);
	std::cout << arrayInt;
	std::cout << "first elem : " << arrayInt[0] << ", last elem : "
		<< arrayInt[arrayInt.size() - 1] << std::endl;

	fillIntArray(&arrayInt);
	std::cout << arrayInt;
	std::cout << "first elem : " << arrayInt[0] << ", last elem : "
		<< arrayInt[arrayInt.size() - 1] << std::endl;

	try
	{
		std::cout << "elem with invalid index : " << arrayInt[arrayInt.size()];
	}
	catch(const std::exception &exception)
	{
		std::cerr << exception.what() << std::endl;
		std::cout << "Type of exception : " << typeid(exception).name() << std::endl;
	}

	std::cout.setf(std::ios::fixed);
	std::cout.precision(2);

	std::cout << std::endl << "==============================================================" << std::endl << std::endl;


	Array<double> arrayDouble(100);
	std::cout << arrayDouble;
	std::cout << "first elem : " << arrayDouble[0] << ", last elem : "
		<< arrayDouble[arrayDouble.size() - 1] << std::endl;

	fillDoubleArray(&arrayDouble);
	std::cout << arrayDouble;
	std::cout << "first elem : " << arrayDouble[0] << ", last elem : "
		<< arrayDouble[arrayDouble.size() - 1] << std::endl;

	try
	{
		std::cout << "elem with invalid index : " << arrayDouble[arrayDouble.size()];
	}
	catch(const std::exception &exception)
	{
		std::cerr << exception.what() << std::endl;
		std::cout << "Type of exception : " << typeid(exception).name() << std::endl;
	}
	
	return (0);
}
