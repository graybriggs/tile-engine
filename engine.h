
#ifndef ENGINE_H
#define ENGINE_H

#include <vector>

#ifdef WINDOWS
  #include "SDL.h"
#else
  #include "SDL2/SDL.h"
#endif

class GameStates;

class Engine {
public:

	void init();
	void cleanup();
	void changeState(GameStates* nextState);
	void pushState(GameStates* state);
	void popState();
	
	void input();
	void update();
	void render();
	bool isRunning();
	void quit();

    SDL_Renderer* getRenderer();

private:
    SDL_Window* window;
    SDL_Surface* screen;
	SDL_Renderer* renderer;

    SDL_Event event;

	std::vector<GameStates*> states;

	bool running = false;
};

#endif

