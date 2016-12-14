#include "predator.h"
#include "prey.h"
#include "glut_app.h"

#include <vector>

Predator::Predator() : Creature() {
	mSinceEat = 0;
}

Predator::Predator(int x, int y) : Creature(x, y) {
	mSinceEat = 0;
}

void Predator::draw(int posX, int posY, int width, int height) {
	glColor3d(1, 0, 0);
	DrawRectangle(posX, posY, width, height);
}

bool Predator::shouldDie() {
	return (mSinceEat > 3);
}

bool Predator::makeMove(std::vector< std::vector<Creature*> > &creatureMap) {
	mMoveCount++;

	bool north = (getY() > 0) && !(dynamic_cast<Predator*>(creatureMap[getX()][getY()-1]));
	bool south = (getY() < creatureMap[0].size()-1) && !(dynamic_cast<Predator*>(creatureMap[getX()][getY()+1]));
	bool east = (getX() < creatureMap.size()-1) && !(dynamic_cast<Predator*>(creatureMap[getX()+1][getY()]));
	bool west = (getX() > 0) && !(dynamic_cast<Predator*>(creatureMap[getX()-1][getY()]));

	bool pnorth, psouth, peast, pwest;
	pnorth = psouth = peast = pwest = false;

	if (north) {
		pnorth = (creatureMap[getX()][getY()-1] != 0);
	}
	if (south) {
		psouth = (creatureMap[getX()][getY()+1] != 0);
	}
	if (east) {
		peast = (creatureMap[getX()+1][getY()] != 0);
	}
	if (west) {
		pwest = (creatureMap[getX()-1][getY()] != 0);
	}

	bool willFeast = (pnorth || psouth || peast || pwest); // Prey in adjacent cells

	if (willFeast) {
		// Prey in adjacent cell(s)
		north = pnorth;
		south = psouth;
		east = peast;
		west = pwest;
	}

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

	int moveX, moveY;
	moveX = moveY = 0;
	switch (choices[rand() % numTrues]) {
		case 0:
			moveY -= 1;
			break;
		case 1:
			moveY += 1;
			break;
		case 2:
			moveX += 1;
			break;
		case 3:
			moveX -= 1;
			break;
	}
	if (willFeast) {
		creatureMap[getX() + moveX][getY() + moveY]->getEaten();
	} else {
		mSinceEat++;
	}
	creatureMap[getX()][getY()] = 0;
	mX += moveX;
	mY += moveY;
	creatureMap[getX()][getY()] = this;

	return true;
}
