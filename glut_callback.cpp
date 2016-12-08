#include "glut_app.h"
#include <iostream>
#include <cstdlib>

//
// GLUT callback functions
//

// int g_x = 300;
// int g_circle_x = 50;
// int g_circle_y = 50;

// This callback function gets called by the Glut
// system whenever it decides things need to be redrawn.
void display(void)
{
  glClear(GL_COLOR_BUFFER_BIT);

  // Test lines that draw all three shapes and some text.
  // Delete these when you get your code working.
  // glColor3d(0.25,0.75,0.5);
  // DrawRectangle(200, 200, 250, 250);
  // glColor3d(0,0,1);
  // DrawTriangle(g_x, 300, g_x+50, 300, g_x+50, 350);
  // glColor3d(1.0,0.75,0.5);
  // DrawCircle(g_circle_x, g_circle_y, 30);

  // glColor3d(0,0,0);
  // DrawCircle(10, 100, 3);
  // DrawText(10,100,"Can you see this black text and 3 blue shapes?");

  for (size_t i=0; i<15; i++) {
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
      {
        Creature* c = creatures[curCreature];

        // Move the creature
        creatureMap[c->getX()][c->getY()] = 0;
        bool north = (c->getY() > 0);
        bool south = c->getY() < g_map_height-1;
        bool east = c->getX() < g_map_width-1;
        bool west = c->getX() > 0;
        c->makeRandomMove(north, south, east, west);
        creatureMap[c->getX()][c->getY()] = c;

        curCreature = (curCreature + 1) % creatures.size(); // Cycle to next creature
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
  // int xdisplay = x;
  // int ydisplay = g_screen_y - y;
  if (mouse_button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) 
    {
    }
  if (mouse_button == GLUT_LEFT_BUTTON && state == GLUT_UP) 
    {
    }
  glutPostRedisplay();
}

