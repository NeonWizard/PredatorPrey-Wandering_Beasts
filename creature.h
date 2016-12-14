#ifndef CREATURE_H
#define CREATURE_H

#include <cstdlib>
#include <vector>

class Creature {
	public:
		Creature();
		Creature(int x, int y);

		void setPos(int x, int y);
		int getX();
		int getY();

		int getMoveCount();
		void resetMoveCount();

		void getEaten();

		virtual bool makeMove(std::vector< std::vector<Creature*> > &creatureMap);
		virtual void draw(int posX, int posY, int width, int height);
		virtual bool shouldDie();

	protected:
		size_t mX;
		size_t mY;

		int mMoveCount;

		// Forgive me father for I have sinned
		bool mIsEaten;
};

#endif // CREATURE_H
