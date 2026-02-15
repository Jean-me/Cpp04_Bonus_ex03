#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource : public IMateriaSource
{
private:
	AMateria* templates[4];

	void clearTemplates();
	void copyFrom(MateriaSource const & other);

public:
	MateriaSource();
	MateriaSource(MateriaSource const & other);
	MateriaSource & operator=(MateriaSource const & other);
	virtual ~MateriaSource();

	virtual void learnMateria(AMateria* m);
	virtual AMateria* createMateria(std::string const & type);
};

#endif
