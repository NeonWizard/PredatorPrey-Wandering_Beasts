#ifndef PREY_H
#define PREY_H

#include <cstdlib>

#include "creature.h"

class Prey: public Creature {
	public:
		Prey();
		Prey(int x, int y);
		void draw(int posX, int posY, int width, int height);
};

#endif // PREY_H
