#ifndef AWESOME_HPP
#define AWESOME_HPP

#include <iostream>

class	Awesome
{
	private :
		int _n;
	public :
		Awesome(void);
		~Awesome();
		Awesome(const Awesome &awesome);

		int	getN(void) const;
};

std::ostream&	operator<< (std::ostream &out, const Awesome &awesome);

#endif
