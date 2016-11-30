#ifndef PREDATOR_H
#define PREDATOR_H

#include <cstdlib>

#include "creature.h"

class Predator: public Creature {
	public:
		Predator();
		Predator(int x, int y);
};

#endif // PREDATOR_H
