#include "predator.h"
#include "glut_app.h"

Predator::Predator() : Creature() {

}

Predator::Predator(int x, int y) : Creature(x, y) {

}

void Predator::draw(int posX, int posY, int width, int height) {
	glColor3d(1, 0, 0);
	DrawRectangle(posX, posY, width, height);
}
