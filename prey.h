#ifndef PREY_H
#define PREY_H

#include <cstdlib>

#include "creature.h"

class Prey: public Creature {
	public:
		Prey();
		Prey(int x, int y);
};

#endif // PREY_H
