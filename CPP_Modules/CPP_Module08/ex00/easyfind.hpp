#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <exception>
#include <sstream>

template <typename Container>
int		easyfind(const Container &container, int value)
{
	typename Container::const_iterator ret =
		std::find(container.cbegin(), container.cend(), value);
	if (ret == container.cend())
	{
		std::stringstream ss;
		ss << value;
		throw std::runtime_error(ss.str() + " not found");
	}
	return (*ret);
}

#endif
