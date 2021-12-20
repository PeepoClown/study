#ifndef POWERFIST_HPP
#define POWERFIST_HPP

#include "AWeapon.hpp"
#include <string>
#include <iostream>

class	PowerFist : public AWeapon
{
	public :
		PowerFist(void);
		virtual ~PowerFist();
		explicit PowerFist(const std::string &name, int apcost, int damage);
		PowerFist(const PowerFist &powerFist);

		PowerFist&	operator= (const PowerFist &powerFist);

		void	attack(void) const;
};

#endif
