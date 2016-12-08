#ifndef PREDATOR_H
#define PREDATOR_H

#include <cstdlib>

#include "creature.h"

class Predator: public Creature {
	public:
		Predator();
		Predator(int x, int y);
		void draw(int posX, int posY, int width, int height);
};

#endif // PREDATOR_H
