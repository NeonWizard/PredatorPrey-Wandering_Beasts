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

void Creature::makeRandomMove(bool canNorth, bool canSouth, bool canEast, bool canWest) {
	int choices[4];
	int numTrues = 0;
	if (canNorth) {
		choices[numTrues] = 0;
		numTrues++;
	}
	if (canSouth) {
		choices[numTrues] = 1;
		numTrues++;
	}
	if (canEast) {
		choices[numTrues] = 2;
		numTrues++;
	}
	if (canWest) {
		choices[numTrues] = 3;
		numTrues++;
	}
	if (numTrues == 0) return;

	switch (choices[rand() % numTrues]) {
		case 0:
			mY -= 1;
			break;
		case 1:
			mY += 1;
			break;
		case 2:
			mX += 1;
			break;
		case 3:
			mX -= 1;
			break;
	}
}

void Creature::draw(int posX, int posY, int width, int height) {
	glColor3d(0, 0, 0);
	DrawRectangle(posX, posY, width, height);
}
