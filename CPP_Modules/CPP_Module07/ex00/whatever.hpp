#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template <typename T>
void	swap(T &value1, T &value2)
{
	T	tmp = value1;
	value1 = value2;
	value2 = tmp;
}

template <typename T>
T	min(T value1, T value2)
{
	return (value1 < value2 ? value1 : value2);
}

template <typename T>
T	max(T value1, T value2)
{
	return (value1 > value2 ? value1 : value2);
}

#endif
