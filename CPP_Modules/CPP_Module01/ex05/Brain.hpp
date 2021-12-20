#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>
#include <sstream>

class	Brain
{
	private :
		std::string	owner;
	public :
		Brain(void);
		Brain(const std::string &owner);

		std::string	identify(void) const;
};

#endif
