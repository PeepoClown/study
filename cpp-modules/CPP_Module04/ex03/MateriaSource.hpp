#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include "AMateria.hpp"
#include <string>

class	MateriaSource : public IMateriaSource
{
	private :
		AMateria	**materia;
		int			count;
	public :
		MateriaSource(void);
		virtual ~MateriaSource();
		MateriaSource(const MateriaSource &materiaSource);

		MateriaSource&	operator= (const MateriaSource &materiaSource);

		void		learnMateria(AMateria *materia);
		AMateria*	createMateria(const std::string &type);
};

#endif
