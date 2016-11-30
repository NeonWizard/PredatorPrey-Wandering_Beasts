#include "creature.h"

Creature::Creature() {
	
}

Creature::Creature(int x, int y) {
	setPos(x, y);
}

void Creature::setPos(int x, int y) {
	mX = x;
	mY = y;
}

int Creature::getX() {
	return mX;
}

int Creature::getY() {
	return mY;
}

void Creature::makeRandomMove(bool canNorth, bool canSouth, bool canWest, bool canEast) {
	
}
