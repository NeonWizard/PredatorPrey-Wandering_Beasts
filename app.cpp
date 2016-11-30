#include "glut_app.h"
#include "predator.h"
#include "prey.h"

#include <time.h>
#include <cstdlib>
#include <vector>
#include <iostream>

size_t g_map_width = 20;
size_t g_map_height = 15;

std::vector<Creature *> creatures;
// std::vector< std::vector<Creature *> > creatureMap;

// Your initialization code goes here.
void initialize_app()
{
	// Seed the random generator to the time (doesn't need to be seeded again anywhere else)
	srand(time(0));
	
	// Size the creatureMap
	// creatureMap.resize(g_map_width);
	// for (size_t i=0; i<g_map_width; i++) {
	// 	creatureMap[i].resize(g_map_height);
	// }

	int predators = 0;
	int prey = 0;
	// Generate 5 predators and 10 prey
	for (int i = 0; i<15; i++) {
		int x, y;
		x = rand() % g_map_width;
		y = rand() % g_map_height;

		if (rand() % 15 < 10 && prey < 10) {
			prey++;
			// create prey
			std::cout << "Created prey at ("<<x<<", "<<y<<")" << std::endl;
			creatures.push_back(new Predator(x, y));

		}
		else {
			predators++;
			// create predator
			std::cout << "Created predator at ("<<x<<", "<<y<<")" << std::endl;
			creatures.push_back(new Prey(x, y));
		}
	}
}
