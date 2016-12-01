#include "creature.h"
#include "glut_app.h"

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

void Creature::draw(int posX, int posY, int width, int height) {
	glColor3d(0, 0, 0);
	DrawRectangle(posX, posY, width, height);
}
