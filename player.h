
#ifndef PLAYER_H
#define PLAYER_H

#ifdef WINDOWS
  #include "SDL.h"
#else
  #include "SDL2/SDL.h"
#endif

#include "sprite.h"

class Player {
public:

	enum Directions { UP, DOWN, LEFT, RIGHT, UP_LEFT, UP_RIGHT, DOWN_LEFT, DOWN_RIGHT };

	Player(SDL_Renderer* rend)
		: ss(rend)
	{
		ss.loadSpriteSheet("playersheet.bmp");
		sprite = new Sprite(rend, &ss, 600, 375, 32, 32);

		for (int i = 0; i < 8; i++) {
			directions[i] = false;
		}

		box.x = 600;
		box.y = 375;
		box.w = 32;
		box.h = 32;

	}

	void input(SDL_Event event) {

		if (event.type == SDL_KEYDOWN) {

			switch (event.key.keysym.sym) {
			case SDLK_UP:
				if (event.key.keysym.sym == SDLK_LEFT) {
					directions[UP_LEFT] = true;
				}
				else if (event.key.keysym.sym == SDLK_RIGHT) {
					directions[UP_RIGHT] = true;
				}
				else {
					sprite->setClips(0, 0);
					directions[UP] = true;
				}
				break;
			case SDLK_DOWN:
				sprite->setClips(63, 0);
				directions[DOWN] = true;
				break;
			case SDLK_LEFT:
				sprite->setClips(95, 0);
				directions[LEFT] = true;
				break;
			case SDLK_RIGHT:
				sprite->setClips(31, 0);
				directions[RIGHT] = true;
				break;

			default:
				break;
			}
		}
		else if (event.type == SDL_KEYUP) {
			switch (event.key.keysym.sym) {
			case SDLK_UP:
				if (event.key.keysym.sym == SDLK_LEFT) {
					directions[UP_LEFT] = false;
				}
				else if (event.key.keysym.sym == SDLK_RIGHT) {
					directions[UP_RIGHT] = false;
				}
				else {
					directions[UP] = false;
					break;
				}
			case SDLK_DOWN:
				directions[DOWN] = false;
				break;
			case SDLK_LEFT:
				directions[LEFT] = false;
				break;
			case SDLK_RIGHT:
				directions[RIGHT] = false;
				break;
			default:
				break;
			}
		}
	}

	void updatePlayer(float delta) {

		if (directions[UP]) {
			box.y -= (Uint32) 1.0 * delta;
		}
		else if (directions[DOWN]) {
			box.y += (Uint32) 1.0 * delta;
		}
		else if (directions[LEFT]) {
			box.x -= (Uint32) 1.0 * delta;
		}
		else if (directions[RIGHT]) {
			box.x += (Uint32) 1.0 * delta;
		}
		else if (directions[UP_LEFT]) {
			box.y -= (Uint32) 1.0 * delta;
			box.x -= (Uint32) 1.0 * delta;
		}
		else if (directions[UP_RIGHT]) {
			box.y -= (Uint32) 1.0 * delta;
			box.x += (Uint32) 1.0 * delta;
		}
		sprite->setBoundingBox(box);
	}

	void setCollisionBoxPosition(int x, int y) {
		box.x = x;
		box.y = y;
	}

	void setCollisionBox(SDL_Rect b) {
		box = b;
	}

	SDL_Rect getCollisionBox() {
		return box;
	}

	void renderPlayer() {
		sprite->renderSprite();
	}

private:
	SpriteSheet ss;
	Sprite* sprite;
	SDL_Rect box;
	bool directions[8];
};

#endif
