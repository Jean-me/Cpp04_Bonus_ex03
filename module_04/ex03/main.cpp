#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include <iostream>

static void title(const char *s)
{
	std::cout << "\n==== " << s << " ====\n";
}

int main()
{
	title("Subject main");
	IMateriaSource *src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter *me = new Character("me");

	AMateria *tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter *bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;

	title("Extra tests");
	MateriaSource ms;
	ms.learnMateria(new Ice());
	ms.learnMateria(new Cure());
	ms.learnMateria(new Cure());
	ms.learnMateria(new Ice());
	ms.learnMateria(new Ice()); // (idx 0~3) Will be ignored

	Character a("a");
	AMateria *m1 = ms.createMateria("ice");
	AMateria *m2 = ms.createMateria("cure");
	AMateria *m3 = ms.createMateria("cure");
	AMateria *m4 = ms.createMateria("ice");
	a.equip(m1);
	a.equip(m2);
	a.equip(m3);
	a.equip(m4);
	a.equip(ms.createMateria("ice")); // full: ignore

	Character b("b");
	a.use(0, b); // Ice
	a.use(1, b); // Cure
	a.use(2, b); // Cure
	a.use(3, b); // Ice
	a.use(4, b); // will be ignored

	// unequip doesn't delete
	a.unequip(1);
	a.use(1, b); // nothing

	// deep copy
	Character c(a);
	c.use(0, b);

	return 0;
}
