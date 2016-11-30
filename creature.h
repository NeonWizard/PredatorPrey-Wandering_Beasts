#ifndef CREATURE_H
#define CREATURE_H

#include <cstdlib>

class Creature {
	public:
		Creature();
		Creature(int x, int y);

		void setPos(int x, int y);
		int getX();
		int getY();

		void makeRandomMove(bool canNorth, bool canSouth, bool canWest, bool canEast);

	protected:
		size_t mX;
		size_t mY;

};

#endif // CREATURE_H
