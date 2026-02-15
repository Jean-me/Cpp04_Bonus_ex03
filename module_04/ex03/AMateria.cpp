#include "AMateria.hpp"

AMateria::AMateria() : type("default_type") {}

AMateria::AMateria(std::string const & t) : type(t) {}

AMateria::AMateria(AMateria const & other) : type(other.type) {}

AMateria & AMateria::operator=(AMateria const &)
{
	return *this;
}

AMateria::~AMateria() {}

std::string const & AMateria::getType() const { return type; }

void AMateria::use(ICharacter&)
{
}
