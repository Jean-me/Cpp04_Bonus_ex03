#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; ++i)
		templates[i] = 0;
}

MateriaSource::MateriaSource(MateriaSource const &other)
{
	for (int i = 0; i < 4; ++i)
		templates[i] = 0;
	copyFrom(other);
}

MateriaSource &MateriaSource::operator=(MateriaSource const &other)
{
	if (this != &other)
	{
		clearTemplates();
		copyFrom(other);
	}
	return *this;
}

MateriaSource::~MateriaSource()
{
	clearTemplates();
}

void MateriaSource::clearTemplates()
{
	for (int i = 0; i < 4; ++i)
	{
		delete templates[i];
		templates[i] = 0;
	}
}

void MateriaSource::copyFrom(MateriaSource const &other)
{
	for (int i = 0; i < 4; ++i)
	{
		if (other.templates[i])
			templates[i] = other.templates[i]->clone();
		else
			templates[i] = 0;
	}
}

void MateriaSource::learnMateria(AMateria *m)
{
	if (!m)
		return;
	for (int i = 0; i < 4; ++i)
	{
		if (!templates[i])
		{
			templates[i] = m->clone();
			delete m;
			return;
		}
	}
	delete m;
}

AMateria *MateriaSource::createMateria(std::string const &t)
{
	for (int i = 0; i < 4; ++i)
	{
		if (templates[i] && templates[i]->getType() == t)
			return templates[i]->clone();
	}
	return 0;
}
