

#ifndef COLLISION_H
#define COLLISION_H

#ifdef WINDOWS
  #include "SDL.h"
#else
  #include "SDL2/SDL.h"
#endif

bool aabb_collision(SDL_Rect& A, SDL_Rect& B) {

	bool leftA, leftB;
	bool rightA, rightB;
	bool topA, topB;
	bool bottomA, bottomB;

	leftA = A.x;
	rightA = A.x + A.w;
	topA = A.y;
	bottomA = A.y + A.h;

	leftB = B.x;
	rightB = B.x + B.w;
	topB = B.y;
	bottomB = B.y + B.h;

	if (bottomA <= topB)
		return false;

	if (topA >= bottomB)
		return false;

	if (rightA <= leftB)
		return false;

	if (leftA >= rightB)
		return false;

	return true;

}

#endif
