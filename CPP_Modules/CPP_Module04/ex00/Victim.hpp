#ifndef VICTIM_HPP
#define VICTIM_HPP

#include <iostream>
#include <string>

class	Victim
{
	protected :
		std::string	name;
	public :
		Victim(void);
		virtual ~Victim();
		explicit Victim(const std::string &name);
		Victim(const Victim &victim);

		Victim&	operator= (const Victim &victim);

		std::string		getName(void) const;
		virtual void	getPolymorphed(void) const;
};

std::ostream&	operator<< (std::ostream &out, const Victim &victim);

#endif
