#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter
{
private:
	std::string name;
	AMateria* inv[4];

	// unequip でdeleteできないので、落としたMateriaを保持して最後に回収する
	struct Node
	{
		AMateria* m;
		Node* next;
		Node(AMateria* mm, Node* nn) : m(mm), next(nn) {}
	};
	Node* floor;

	void clearInvAndFloor();
	void copyFrom(Character const & other);
	void floorPush(AMateria* m);

public:
	Character();
	Character(std::string const & name);
	Character(Character const & other);
	Character & operator=(Character const & other);
	virtual ~Character();

	virtual std::string const & getName() const;
	virtual void equip(AMateria* m);
	virtual void unequip(int idx);
	virtual void use(int idx, ICharacter& target);
};

#endif
