#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include "ICharacter.hpp"
#include <string>

class	AMateria
{
	protected :
		unsigned int	xp;
		std::string		type;
	public :
		AMateria(void);
		virtual ~AMateria();
		AMateria(const std::string &type);
		AMateria(const AMateria &materia);

		AMateria&	operator= (const AMateria &materia);

		const std::string&	getType(void) const;
		unsigned int		getXP(void) const;

		virtual AMateria*	clone(void) const = 0;
		virtual void		use(ICharacter &target);
};

#endif
