#include "glut_app.h"
#include <iostream>
#include <cstdlib>

#include "predator.h"
#include "prey.h"

//
// GLUT callback functions
//

// This callback function gets called by the Glut
// system whenever it decides things need to be redrawn.
void display(void)
{
  glClear(GL_COLOR_BUFFER_BIT);

  for (size_t i=0; i<creatures.size(); i++) {
    if (creatures[i] == 0) continue;
    double drawX = creatures[i]->getX()*(g_screen_x/g_map_width);
    double drawY = g_screen_y - creatures[i]->getY()*(g_screen_y/g_map_height);
    creatures[i]->draw(
      drawX,
      drawY,
      drawX + (g_screen_x/g_map_width),
      drawY - (g_screen_y/g_map_height)
    );
  }

  glutSwapBuffers();
}


void doRound() {
  Creature* c = creatures[curCreature];

  creatureMap[c->getX()][c->getY()] = 0;
  c->makeMove(creatureMap);
  creatureMap[c->getX()][c->getY()] = c;

  // Reproduction
  if (dynamic_cast<Predator*>(creatures[curCreature]) && (creatures[curCreature]->getMoveCount()+1) % 8 == 0) {
    // Predator reproduction
    Predator* pred = new Predator(creatures[curCreature]->getX(), creatures[curCreature]->getY());
    if (pred->makeMove(creatureMap)) {
      // child could move somewhere
      creatures.push_back(pred);
      pred->resetMoveCount();
      creatureMap[pred->getX()][pred->getY()] = pred;
    }
  } else if (dynamic_cast<Prey*>(creatures[curCreature]) && (creatures[curCreature]->getMoveCount()+1) % 3 == 0) {
    // Prey reproduction
    Prey* prey = new Prey(creatures[curCreature]->getX(), creatures[curCreature]->getY());
    if (prey->makeMove(creatureMap)) {
      // child could move somewhere
      creatures.push_back(prey);
      prey->resetMoveCount();
      creatureMap[prey->getX()][prey->getY()] = prey;
    }
  }

  // Reaper loop
  for (size_t i=0; i<creatures.size(); i++) {
    if (creatures[i] == 0) continue;

    if (creatures[i]->shouldDie()) {
      if (dynamic_cast<Predator*>(creatures[i])) {
        creatureMap[creatures[i]->getX()][creatures[i]->getY()] = 0;
      }
      creatures[i] = 0;
      continue;
    }
  }

  while (1) {
    curCreature = (curCreature + 1) % creatures.size();

    if (curCreature == 0) { // Clean up time
      for (size_t i=creatures.size()-1; i>0; i--) {
        if (creatures[i] == 0) {
          creatures.erase(creatures.begin()+i);
        }
      }
    }

    if (creatures[curCreature] != 0) break; // Break out of the loop when we find a creature
  }
}

// This callback function gets called by the Glut
// system whenever a key is pressed.
void keyboard(unsigned char c, int x, int y)
{
  switch (c) 
    {
    case 'q':
    case 27: // escape character means to quit the program
      exit(0);
      break;
    case 's':
      doRound();
      break;
    case 'a':
      for (size_t i=0; i<creatures.size(); i++) {
        doRound();
      }
      break;
    case 'd':
      std::cout << "--- Debug Info ---" << std::endl;
      std::cout << "Creatures size: " << creatures.size() << std::endl;
      std::cout << "Current creature: " << curCreature << std::endl;
    default:
      return; // if we don't care, return without glutPostRedisplay()
    }

  glutPostRedisplay();
}


// This callback function gets called by the Glut
// system whenever the window is resized by the user.
void reshape(int w, int h)
{
  // Reset our global variables to the new width and height.
  g_screen_x = w;
  g_screen_y = h;

  // Set the pixel resolution of the final picture (Screen coordinates).
  glViewport(0, 0, w, h);

  // Set the projection mode to 2D orthographic, and set the world coordinates:
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0, w, 0, h);
  glMatrixMode(GL_MODELVIEW);

}

// This callback function gets called by the Glut
// system whenever any mouse button goes up or down.
void mouse(int mouse_button, int state, int x, int y)
{
  // translate pixel coordinates to display coordinates
  if (mouse_button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) 
    {
    }
  if (mouse_button == GLUT_LEFT_BUTTON && state == GLUT_UP) 
    {
    }
  glutPostRedisplay();
}

