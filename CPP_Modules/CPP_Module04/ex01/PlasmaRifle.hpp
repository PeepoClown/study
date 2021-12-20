#ifndef PLASMARIFLE_HPP
#define PLASMARIFLE_HPP

#include "AWeapon.hpp"
#include <string>
#include <iostream>

class	PlasmaRifle : public AWeapon
{
	public :
		PlasmaRifle(void);
		virtual ~PlasmaRifle();
		explicit PlasmaRifle(const std::string &name, int apcost, int damage);
		PlasmaRifle(const PlasmaRifle &plasmaRifle);

		PlasmaRifle&	operator= (const PlasmaRifle &plasmaRifle);

		void	attack(void) const;
};

#endif
