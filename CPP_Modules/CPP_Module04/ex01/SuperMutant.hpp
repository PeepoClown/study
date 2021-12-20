#ifndef SUPERMUTANT_HPP
#define SUPERMUTANT_HPP

#include "Enemy.hpp"
#include <string>
#include <iostream>

class	SuperMutant : public Enemy
{
	public :
		SuperMutant(void);
		virtual ~SuperMutant();
		explicit SuperMutant(int hp, const std::string &type);
		SuperMutant(const SuperMutant &superMutant);

		SuperMutant&	operator= (const SuperMutant &superMutant);

		void	takeDamage(int damage);
};

#endif
