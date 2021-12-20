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
		explicit Awesome(int n);
		Awesome(const Awesome &awesome);

		Awesome&	operator= (const Awesome &awesome);
		bool		operator== (const Awesome &rhs);
		bool		operator!= (const Awesome &rhs);
		bool		operator> (const Awesome &rhs);
		bool		operator< (const Awesome &rhs);
		bool		operator>= (const Awesome &rhs);
		bool		operator<= (const Awesome &rhs);

		int	getN(void) const;
};

std::ostream&	operator<< (std::ostream &out, const Awesome &awesome);

#endif
