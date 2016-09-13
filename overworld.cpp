

#include <iostream>

#include "overworld.h"

//#include "player.h"

void Overworld::init() {

    /*

	SpriteSheet ss(renderer);
	ss.loadSpriteSheet("tilesheet.bmp");

	std::vector<Sprite> tiles;
	setupBgTiles(renderer, ss, tiles);

	Player player(renderer);

	SDL_Rect scrollBounds{ 200, 200, 1000, 550 };

	/////////////////

	Uint32 currentTime = SDL_GetTicks();
	Uint32 lastTime = SDL_GetTicks();
	Uint32 updateCounter = 0;
	const float deltaTime60 = 1000 / 60.0f; // 1 frame every 60 fps
	float accumulator = 0;
   
    */

    std::cout << "Initialising overworld" << std::endl;
}

void Overworld::cleanup() {

}

void Overworld::pause() {

}

void Overworld::resume() {

}

void Overworld::input(Engine* sMan)  {

    std::cout << "Overworld input" << std::endl;


/*
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				done = true;
			}

			else if (event.type == SDL_KEYDOWN) {

				switch (event.key.keysym.sym) {
				case SDLK_UP:
					break;
				case SDLK_DOWN:
					break;
				case SDLK_LEFT:
					break;
				case SDLK_RIGHT:
					break;

					////
				case SDLK_ESCAPE:
					done = true;
					break;
				default:
					break;
				}
			}
			else if (event.type == SDL_KEYUP) {
				switch (event.key.keysym.sym) {
				case SDLK_UP:
					break;
				case SDLK_DOWN:
					break;
				case SDLK_LEFT:
					break;
				case SDLK_RIGHT:
					break;
				default:
					break;
				}
			}
		}

		player->input(event);
*/
}

void Overworld::update(Engine* sMan) {

        /*

		currentTime = SDL_GetTicks();
		Uint32 timePassed = currentTime - lastTime;
		lastTime = currentTime;
		accumulator += timePassed;


		while (accumulator >= deltaTime60) {
			update(player, tiles, scrollBounds, deltaTime60);
			accumulator -= deltaTime60;
		}

        */

        std::cout << "Overworld update " << std::endl;

}

void Overworld::render(Engine* sMan) {

/*
	for (auto& tile : tiles) {
		tile.renderSprite();
	}

    std::cout << "Overworld render" << std::endl;
*/
}


