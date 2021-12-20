#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <cstdlib>

template <typename T>
void	print(const T &value)
{
	std::cout << value << " ";
}

template <typename T>
int		cmp(const T &value1, const T &value2)
{
	if (value1 > value2)
		return (1);
	else if (value1 == value2)
		return (0);
	else
		return (-1);
}

template <typename T>
void	iter(T *array, std::size_t length, void (*func)(const T&))
{
	for (std::size_t i = 0; i < length; i++)
		func(array[i]);
}

template <typename T>
void	iter(T *array, std::size_t length, void (*func)(T&))
{
	for (std::size_t i = 0; i < length; i++)
		func(array[i]);
}


template <typename T>
void	iter(T *array, std::size_t length, int (*cmp)(const T&, const T&))
{
	for (std::size_t i = 0; i < length - 1; i++)
	{
		std::size_t minIndex = i;
		for (std::size_t j = i + 1; j < length; j++)
		{
			if (cmp(array[minIndex], array[j]) > 0)
				minIndex = j;
		}
		if (minIndex != i)
		{
			T tmp = array[i];
			array[i] = array[minIndex];
			array[minIndex] = tmp;
		}
	}
}

#endif
