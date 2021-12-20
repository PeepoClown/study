#ifndef PEON_HPP
#define PEON_HPP

#include "Victim.hpp"
#include <iostream>
#include <string>

class	Peon : public Victim
{
	public :
		Peon(void);
		virtual ~Peon();
		explicit Peon(const std::string &name);
		Peon(const Peon &peon);

		Peon&	operator= (const Peon &peon);

		void	getPolymorphed(void) const;
};

#endif
