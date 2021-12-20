#include "Enemy.hpp"

Enemy::Enemy(void)
	: hp(0), type("")
{ }

Enemy::~Enemy()
{ }

Enemy::Enemy(int hp, const std::string &type)
	: hp(hp), type(type)
{ }

Enemy::Enemy(const Enemy &enemy)
{
	*this = enemy;
}

Enemy&	Enemy::operator= (const Enemy &enemy)
{
	this->hp = enemy.hp;
	this->type = enemy.type;
	return (*this);
}

std::string	Enemy::getType(void) const
{
	return (this->type);
}

int			Enemy::getHP(void) const
{
	return (this->hp);
}

void		Enemy::takeDamage(int damage)
{
	if (damage < 0)
		return ;

	if (this->hp - damage >= 0)
		this->hp -= damage;
	else
		this->hp = 0;
}
