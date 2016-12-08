#include "prey.h"
#include "glut_app.h"

Prey::Prey() : Creature() {

}

Prey::Prey(int x, int y) : Creature(x, y) {

}

void Prey::draw(int posX, int posY, int width, int height) {
	glColor3d(0, 1, 0);
	DrawRectangle(posX, posY, width, height);
}
