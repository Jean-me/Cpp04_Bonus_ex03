#include "Character.hpp"

Character::Character() : name("default_name"), floor(0)
{
	for (int i = 0; i < 4; ++i)
		inv[i] = 0;
}

Character::Character(std::string const &n) : name(n), floor(0)
{
	for (int i = 0; i < 4; ++i)
		inv[i] = 0;
}

Character::Character(Character const &other) : name(other.name), floor(0)
{
	for (int i = 0; i < 4; ++i)
		inv[i] = 0;
	copyFrom(other);
}

Character &Character::operator=(Character const &other)
{
	if (this != &other)
	{
		clearInvAndFloor();
		name = other.name;
		copyFrom(other);
	}
	return *this;
}

Character::~Character()
{
	clearInvAndFloor();
}

void Character::clearInvAndFloor()
{
	for (int i = 0; i < 4; ++i)
	{
		delete inv[i];
		inv[i] = 0;
	}
	while (floor)
	{
		Node *tmp = floor->next;
		delete floor->m;
		delete floor;
		floor = tmp;
	}
}

void Character::copyFrom(Character const &other)
{
	for (int i = 0; i < 4; ++i)
	{
		if (other.inv[i])
			inv[i] = other.inv[i]->clone();
		else
			inv[i] = 0;
	}
	floor = 0;
}

void Character::floorPush(AMateria *m)
{
	if (!m)
		return;
	floor = new Node(m, floor);
}

std::string const &Character::getName() const { return name; }

void Character::equip(AMateria *m)
{
	if (!m)
		return;
	for (int i = 0; i < 4; ++i)
	{
		if (!inv[i])
		{
			inv[i] = m;
			return;
		}
	}
	delete m;
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= 4)
		return;
	if (!inv[idx])
		return;

	floorPush(inv[idx]);
	inv[idx] = 0;
}

void Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx >= 4)
		return;
	if (!inv[idx])
		return;
	inv[idx]->use(target);
}
