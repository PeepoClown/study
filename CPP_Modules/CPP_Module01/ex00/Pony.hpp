#ifndef PONY_HPP
#define PONY_HPP

#include <iostream>
#include <string>

class	Pony
{
	private :
		std::string	name;
		size_t		height;
		size_t		weight;
	public :
		Pony(void);
		Pony(const std::string &name, size_t height, size_t weight);

		void	doSmth(void);
};

#endif
