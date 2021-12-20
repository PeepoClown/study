#ifndef AWEAPON_HPP
#define AWEAPON_HPP

#include <string>

class	AWeapon
{
	protected :
		std::string	name;
		int			apcost,
					damage;
	public :
		AWeapon(void);
		virtual ~AWeapon();
		explicit AWeapon(const std::string &name, int apcost, int damage);
		AWeapon(const AWeapon &weapon);

		AWeapon&	operator= (const AWeapon &weapon);

		std::string	getName(void) const;
		int			getAPCost(void) const;
		int			getDamage(void) const;

		virtual void	attack(void) const = 0;
};

#endif
