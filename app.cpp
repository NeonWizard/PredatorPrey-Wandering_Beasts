#include "glut_app.h"
#include "predator.h"
#include "prey.h"

#include <time.h>
#include <cstdlib>
#include <vector>
#include <algorithm>

size_t g_map_width = 20;
size_t g_map_height = 20;

size_t curCreature = 0;
std::vector<Creature *> creatures;
std::vector< std::vector<Creature *> > creatureMap;

// Your initialization code goes here.
void initialize_app()
{
	// Seed the random generator to the time (doesn't need to be seeded again anywhere else)
	srand(time(0));
	
	// Size the creatureMap
	creatureMap.resize(g_map_width);
	for (size_t i=0; i<g_map_width; i++) {
		creatureMap[i].resize(g_map_height);
	}

	int preyCount = 0;
	// Generate 5 predators and 25 prey
	for (int i = 0; i<30; i++) {
		int x, y;
		x = rand() % g_map_width;
		y = rand() % g_map_height;
		while (creatureMap[x][y] != 0) {
			x = rand() % g_map_width;
			y = rand() % g_map_height;
		}

		if (preyCount < 25) {
			preyCount++;
			// create prey
			Prey* prey = new Prey(x, y);
			creatures.push_back(prey);
			creatureMap[x][y] = prey;
		} else {
			// create predator
			Predator* pred = new Predator(x, y);
			creatures.push_back(pred);
			creatureMap[x][y] = pred;
		}
	}
	std::random_shuffle(creatures.begin(), creatures.end());
}
