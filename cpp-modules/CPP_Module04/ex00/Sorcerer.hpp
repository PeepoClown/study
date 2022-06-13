#ifndef SORCERER_HPP
#define SORCERER_HPP

#include "Victim.hpp"
#include <iostream>
#include <string>

class	Sorcerer
{
	private :
		std::string	name,
					title;
	public :
		Sorcerer(void);
		~Sorcerer();
		explicit Sorcerer(const std::string &name, const std::string &title);
		Sorcerer(const Sorcerer &sorcerer);

		Sorcerer&	operator= (const Sorcerer &sorcerer);

		std::string	getName(void) const;
		std::string	getTitle(void) const;

		void	polymorph(const Victim &victim) const;
};

std::ostream&	operator<< (std::ostream &out, const Sorcerer &sorcerer);

#endif
