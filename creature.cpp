#include "creature.h"
#include "glut_app.h"

#include <vector>
#include <iostream>

Creature::Creature() {
	mIsEaten = false;
	mMoveCount = 0;
}

Creature::Creature(int x, int y) {
	setPos(x, y);
	mIsEaten = false;
	mMoveCount = 0;
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

bool Creature::shouldDie() {
	return mIsEaten;
}

void Creature::getEaten() {
	mIsEaten = true;
}

int Creature::getMoveCount() {
	return mMoveCount;
}

void Creature::resetMoveCount() {
	mMoveCount = 0;
}

bool Creature::makeMove(std::vector< std::vector<Creature*> > &creatureMap) {
	mMoveCount++;

	bool north = (getY() > 0) && creatureMap[getX()][getY()-1] == 0;
	bool south = (getY() < creatureMap[0].size()-1) && creatureMap[getX()][getY()+1] == 0;
	bool east = (getX() < creatureMap.size()-1) && creatureMap[getX()+1][getY()] == 0;
	bool west = (getX() > 0) && creatureMap[getX()-1][getY()] == 0;

	int choices[4];
	int numTrues = 0;
	if (north) {
		choices[numTrues] = 0;
		numTrues++;
	}
	if (south) {
		choices[numTrues] = 1;
		numTrues++;
	}
	if (east) {
		choices[numTrues] = 2;
		numTrues++;
	}
	if (west) {
		choices[numTrues] = 3;
		numTrues++;
	}
	if (numTrues == 0) return false;

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

	return true;
}

void Creature::draw(int posX, int posY, int width, int height) {
	glColor3d(0, 0, 0);
	DrawRectangle(posX, posY, width, height);
}
