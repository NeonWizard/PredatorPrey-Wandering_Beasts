#ifndef PREDATOR_H
#define PREDATOR_H

#include <cstdlib>
#include <vector>
#include <iostream>

#include "creature.h"

class Predator: public Creature {
	public:
		Predator();
		Predator(int x, int y);
		void draw(int posX, int posY, int width, int height);
		bool makeMove(std::vector< std::vector<Creature*> > &creatureMap);
		bool shouldDie();

	private:
		int mSinceEat;
};

#endif // PREDATOR_H
