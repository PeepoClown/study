#ifndef RADSCORPION_HPP
#define RADSCORPION_HPP

#include "Enemy.hpp"
#include <string>
#include <iostream>

class	RadScorpion : public Enemy
{
	public :
		RadScorpion(void);
		virtual ~RadScorpion();
		explicit RadScorpion(int hp, const std::string &type);
		RadScorpion(const RadScorpion &radScorpion);

		RadScorpion&	operator= (const RadScorpion &radScorpion);

		void	takeDamage(int damage);
};

#endif
