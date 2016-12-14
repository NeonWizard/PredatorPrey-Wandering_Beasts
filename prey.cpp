#include "prey.h"
#include "predator.h"
#include "glut_app.h"

#include <vector>

Prey::Prey() : Creature() {
}

Prey::Prey(int x, int y) : Creature(x, y) {
}

void Prey::draw(int posX, int posY, int width, int height) {
	glColor3d(0, 1, 0);
	DrawRectangle(posX, posY, width, height);
}

// void Prey::makeMove(std::vector< std::vector<Creature*> > &creatureMap) {
// 	Creature::makeMove(creatureMap);
// }
