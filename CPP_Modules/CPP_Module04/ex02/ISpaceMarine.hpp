#ifndef ISPACEMARINE_HPP
#define ISPACEMARINE_HPP

class	ISpaceMarine
{
	public:
		virtual ~ISpaceMarine() { }

		virtual ISpaceMarine*	clone(void) const = 0;
		virtual void			battleCry(void) const = 0;
		virtual void			rangedAttack(void) const = 0;
		virtual void			meleeAttack(void) const = 0;
};

#endif
