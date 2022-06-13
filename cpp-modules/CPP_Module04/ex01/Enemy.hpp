#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <string>

class	Enemy
{
	protected :
		int			hp;
		std::string	type;
	public :
		Enemy(void);
		virtual ~Enemy();
		Enemy(int hp, const std::string &type);
		Enemy(const Enemy &enemy);

		Enemy&	operator= (const Enemy &enemy);

		std::string	getType(void) const;
		int			getHP(void) const;

		virtual void	takeDamage(int damage);
};

#endif
