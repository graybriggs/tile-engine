

#include "state.h"

#include <iostream>

void Engine::init() {
    std::cout << "Starting Engine..." << std::endl;

	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER);

	SDL_Event event;
	bool done = false;

	window = SDL_CreateWindow("Tile Engine", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1200, 750, SDL_WINDOW_SHOWN);
	screen = SDL_GetWindowSurface(window);

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);


    running = true;
}

void Engine::cleanup() {

   	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
    SDL_Quit();

}

void Engine::changeState(GameStates* nextState) {

	if (!states.empty()) {
		states.back()->cleanup();
	}

	states.push_back(nextState);
	states.back()->init();
}

void Engine::pushState(GameStates* state) {
    states.push_back(state);
}

void Engine::popState() {}
	
void Engine::input() {

		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				running = false;
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
					running = false;
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

    states.back()->input(this);
}
void Engine::update() {
	states.back()->update(this);
}

void Engine::render() {

	SDL_RenderClear(renderer);
	SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0xFF, 0xFF, 0xFF));
	states.back()->render(this);
	SDL_RenderPresent(renderer);
}

bool Engine::isRunning() {
    return running;
}

void Engine::quit() { running = false; }

SDL_Renderer* Engine::getRenderer() {
    return renderer;
}

