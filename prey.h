#ifndef PREY_H
#define PREY_H

#include <cstdlib>
#include <vector>

#include "creature.h"

class Prey: public Creature {
	public:
		Prey();
		Prey(int x, int y);
		void draw(int posX, int posY, int width, int height);
		// void makeMove(std::vector< std::vector<Creature*> > &creatureMap);
};

#endif // PREY_H
